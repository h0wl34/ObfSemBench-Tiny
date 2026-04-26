import os
import re
import subprocess
import pandas as pd
from tqdm import tqdm
from concurrent.futures import ProcessPoolExecutor, as_completed

# === НАСТРОЙКИ ===
SOURCE_ROOT = "/dataset"
OUTPUT_DIR = "/dataset/bins"
DATASET_FILE = "/dataset/semantic_benchmark.csv"
NUM_CORES = 10 

COMPILERS = {
    "gcc_O0": ["gcc", "-c", "-m64", "-O0", "-g"],
    "gcc_O2": ["gcc", "-c", "-m64", "-O2", "-g", "-fkeep-inline-functions"],
    "gcc_Os": ["gcc", "-c", "-m64", "-Os", "-g", "-fkeep-inline-functions"],
}

FUNC_REGEX = re.compile(
    r'^\s*'
    r'(?:'
        r'(?:[a-zA-Z_][\w\s*]*?)'               # тип + указатели + пробелы
        r'\s*'
        r'(?:__attribute__\s*\(\([^)]+\)\)\s*)*' # любые атрибуты
        r'\s*'
    r')?'
    r'([a-zA-Z_]\w*)'                           # имя
    r'\s*'
    r'\([^)]*(?:\([^)]*\)[^)]*)*\)'             # аргументы
    r'\s*\{',
    re.MULTILINE | re.DOTALL
)

def extract_version(filename):
    match = re.search(r'(v[1-5])', str(filename).lower())
    return match.group(1).upper() if match else "V1"

def get_first_function_name(src_file):
    with open(src_file, "r", encoding="utf-8") as f:
        code = f.read()
    
    # Ищем все функции, подходящие под сигнатуру
    matches = FUNC_REGEX.finditer(code)
    
    for match in matches:
        func_name = match.group(1)
        # Пропускаем служебные функции
        if "force_use" not in func_name and "level" not in func_name:
            return func_name
            
    return None

def get_function_address(obj_path, func_name):
    result = subprocess.run(["nm", "-C", obj_path], capture_output=True, text=True, check=True)
    for line in result.stdout.splitlines():
        parts = line.strip().split()
        if len(parts) == 3:
            addr, typ, name = parts
            if name == func_name:
                return int(addr, 16)
    return None

def extract_function_asm(obj_path, func_name):
    addr = get_function_address(obj_path, func_name)
    if addr is None:
        return None
        
    # Добавляем флаг -r и -M intel
    result = subprocess.run(["objdump", "-d", "-r", "-M", "intel", "--section=.text", obj_path],
                            capture_output=True, text=True, check=True)
    lines = result.stdout.splitlines()
    
    func_lines = []
    in_func = False
    
    # Регулярка для релокаций (Windows PE формат из твоего лога)
    # Пример: "                        1d: R_X86_64_PC32       __imp_MessageBoxA"
    RELOC_REGEX = re.compile(r':\s+(R_X86_64_\w+|R_386_\w+)\s+(.+)$')

    for line in lines:
        if f"<{func_name}>:" in line:
            in_func = True
            continue
        elif in_func and re.match(r'^[0-9a-fA-F]+ <.*>:', line):
            break
        elif in_func:
            if not line.strip(): continue
            
            # Проверяем, не релокация ли это
            reloc_match = RELOC_REGEX.search(line)
            
            if reloc_match:
                # Если это релокация, пытаемся приклеить имя к предыдущей инструкции
                if len(func_lines) > 0:
                    symbol_name = reloc_match.group(2).strip()
                    
                    # Игнорируем ссылки на секции .rdata, .data, .text
                    if symbol_name.startswith('.'):
                        # Это ссылка на строку или глобальную переменную.
                        # Можно было бы добавить комментарий, но для API это не нужно.
                        continue

                    prev_line = func_lines[-1]
                    
                    # Ищем инструкции вызова (call, jmp) или загрузки адреса (lea, mov)
                    # Учитываем префиксы типа "rex.W jmp"
                    if 'call' in prev_line or 'jmp' in prev_line:
                        # Заменяем операнд на имя символа
                        # Ищем последнее слово в инструкции и меняем его? Нет, там может быть [rip+0x0]
                        
                        # Стратегия: Заменяем всё после мнемоники на имя символа
                        # Но мнемоника может быть "rex.W jmp".
                        
                        # Просто заменяем "QWORD PTR [rip+0x0]" и подобные конструкции
                        # Или тупо добавляем комментарий, чтобы clean_and_rebase его увидел?
                        # Нет, нам нужно, чтобы CLAP увидел "call MessageBoxA"
                        
                        # Универсальный патч: заменяем всё после call/jmp
                        new_line = re.sub(r'(call|jmp).*$', f'\\1 {symbol_name}', prev_line)
                        
                        # Если регулярка не сработала (например rex.W jmp), пробуем грубее
                        if new_line == prev_line:
                             # Ищем индекс опкода
                             idx = prev_line.find('call')
                             if idx == -1: idx = prev_line.find('jmp')
                             if idx != -1:
                                 new_line = prev_line[:idx] + prev_line[idx:].split()[0] + " " + symbol_name
                        
                        func_lines[-1] = new_line
                        
                    elif 'lea' in prev_line or 'mov' in prev_line:
                         # Это загрузка адреса функции (GetProcAddress)
                         # lea rcx,[rip+0x11] -> lea rcx, __imp_GetProcAddress
                         # Это сложно заменить корректно, не сломав синтаксис.
                         # Добавим имя как комментарий в конец строки?
                         # CLAP не видит комментарии, если мы их чистим.
                         # Давай заменим аргумент [rip+...] на имя.
                         new_line = re.sub(r'\[rip\+0x[0-9a-f]+\]', symbol_name, prev_line)
                         func_lines[-1] = new_line
                continue

            func_lines.append(line)
            
    if not func_lines:
        return None
    return "\n".join(func_lines)


def compile_and_extract(task):
    cat, behavior, src_file, comp_name, flags = task
    src_full = os.path.join(SOURCE_ROOT, cat, behavior, src_file)
    func_name = get_first_function_name(src_full)
    if func_name is None:
        return None

    base_name = src_file.replace(".c", "")
    obfuscation = extract_version(base_name)
    out_name = f"{cat}_{behavior}_{base_name}_{comp_name}.o"
    out_path = os.path.join(OUTPUT_DIR, out_name)
    cmd = flags + [src_full, "-o", out_path]
    try:
        subprocess.run(cmd, check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        asm_code = extract_function_asm(out_path, func_name)
        
        if asm_code is None:
            print(f"⚠️ No assembly extracted for {src_full} with {comp_name}")
            return None
        
        if asm_code:
            return {
                "category": cat,
                "query": cat.replace("_", " "),
                "behavior": behavior,
                "filename": out_name,
                "compiler": comp_name,
                "raw_asm": asm_code,
                "obfuscation": obfuscation
            }
            
    except subprocess.CalledProcessError:
        print(f"⚠️ Compilation failed: {out_path}")
    except Exception as e:
        print(f"Error: {e}")
    return None

def build_benchmark():
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    records = []

    categories = [d for d in os.listdir(SOURCE_ROOT) if os.path.isdir(os.path.join(SOURCE_ROOT, d))]
    print(f"Found {len(categories)} categories.")

    # Создаем список всех задач
    tasks = []
    for cat in categories:
        cat_path = os.path.join(SOURCE_ROOT, cat)
        for behavior in os.listdir(cat_path):
            behavior_path = os.path.join(cat_path, behavior)
            for src_file in os.listdir(behavior_path):
                if src_file.endswith(".c"):
                    for comp_name, flags in COMPILERS.items():
                        tasks.append((cat, behavior, src_file, comp_name, flags))

    # Параллельная обработка
    with ProcessPoolExecutor(max_workers=NUM_CORES) as executor:
        futures = {executor.submit(compile_and_extract, t): t for t in tasks}
        for f in tqdm(as_completed(futures), total=len(futures), desc="Processing Files"):
            result = f.result()
            if result:
                records.append(result)

    df = pd.DataFrame(records)
    df.to_csv(DATASET_FILE, index=False)
    print(f"\n✅ Benchmark created: {len(df)} samples.")
    print(df['category'].value_counts())

if __name__ == "__main__":
    build_benchmark()