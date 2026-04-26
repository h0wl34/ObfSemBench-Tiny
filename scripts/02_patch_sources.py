import os
import re

SOURCE_ROOT = "/dataset/bins"

# Универсальный regex для функций
func_pattern = re.compile(
    r'''^
    (\s*                                 # пробелы перед сигнатурой
     (?:[a-zA-Z_][\w\s\*\d]*\s+)+        # тип функции (может быть несколько слов: unsigned long *)
     )                                    
    ([a-zA-Z_]\w*)                        # имя функции
    (\s*\([^;{]*\))                       # аргументы функции
    (\s*\{)                               # открывающая скобка
    ''',
    re.MULTILINE | re.VERBOSE
)

# Атрибуты, которые нужно вставить
ATTRIBUTES = ["__attribute__((noinline))", "__attribute__((used))"]

for root, dirs, files in os.walk(SOURCE_ROOT):
    for f in files:
        if not f.endswith(".c"):
            continue
        
        path = os.path.join(root, f)
        with open(path, "r", encoding="utf-8") as infile:
            code = infile.read()
        
        def replacer(match):
            prefix = match.group(1)
            name = match.group(2)
            args = match.group(3)
            brace = match.group(4)

            # Удаляем уже существующие нужные атрибуты из prefix
            for attr in ATTRIBUTES:
                prefix = prefix.replace(attr, "")
            prefix = prefix.rstrip()  # убираем лишние пробелы

            # Добавляем ровно один экземпляр каждого атрибута перед именем функции
            attrs_str = " ".join(ATTRIBUTES)
            return f"{prefix} {attrs_str} {name}{args}{brace}"

        new_code, count = func_pattern.subn(replacer, code)
        
        if count > 0:
            with open(path, "w", encoding="utf-8") as outfile:
                outfile.write(new_code)
            print(f"Patched {count} functions in {path}")