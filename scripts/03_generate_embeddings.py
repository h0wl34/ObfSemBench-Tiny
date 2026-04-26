import re
import torch
import pandas as pd
from tqdm import tqdm
from transformers import AutoTokenizer, AutoModel

# === КОНФИГ ===
INPUT_CSV = "/dataset/semantic_benchmark.csv"
OUTPUT_CSV = "/dataset/semantic_benchmark_with_emb.csv"

MODEL_NAME = "hustcw/clap-asm"
MAX_CODE_LEN = 512
BATCH_SIZE = 32

# === УСТРОЙСТВО ===
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"🚀 Loading CLAP to {device}...")

tokenizer = AutoTokenizer.from_pretrained(MODEL_NAME, trust_remote_code=True)
tokenizer.model_max_length = MAX_CODE_LEN
model = AutoModel.from_pretrained(MODEL_NAME, trust_remote_code=True).to(device)
model.eval()

HEX_PATTERN = re.compile(r'0x[0-9a-fA-F]+')

def clean_and_rebase(raw_code):
    """Cleaning objdump, removing __imp_ and replacing addreses with INSTRk (for CLAP-ASM)"""
    lines = raw_code.strip().split('\n')
    clean_lines = []
    addr_to_idx = {}
    valid_count = 0

    OBJDUMP_RE = re.compile(r'^\s*([0-9a-fA-F]+):\s+(?:[0-9a-fA-F]{2}\s+)+(.*)$')
    HEX_PATTERN = re.compile(r'0x[0-9a-f]+')

    for line in lines:
        match = OBJDUMP_RE.match(line)
        if not match: continue

        addr_str = match.group(1).lower()
        instr_text = match.group(2).strip().lower() # Приводим к нижнему регистру

        # 1. Убираем комментарии objdump (например: jmp 88 <find_index+0x88>)
        if '<' in instr_text:
            instr_text = instr_text[:instr_text.find('<')].strip()

        # 2. УДАЛЯЕМ ПРЕФИКС __imp_ (ЭТО ВАЖНО ДЛЯ API)
        if '__imp_' in instr_text:
            instr_text = instr_text.replace('__imp_', '')

        # Пропускаем мусор
        if not instr_text or 'nop' in instr_text or 'int3' in instr_text:
            continue

        valid_count += 1
        addr_hex = f"0x{addr_str}"
        addr_to_idx[addr_hex] = valid_count

        # ИСПРАВЛЕНИЕ ПРЫЖКОВ
        parts = instr_text.split()
        if len(parts) > 1 and (parts[0].startswith('j') or parts[0] == 'call'):
            target = parts[-1]
            if all(c in '0123456789abcdef' for c in target) and not target.startswith('0x'):
                if target not in ['eax', 'ebx', 'ecx', 'edx', 'rax', 'rbx', 'rcx', 'rdx', 'rsi', 'rdi', 'rsp', 'rbp']:
                    parts[-1] = f"0x{target}"
                    instr_text = " ".join(parts)

        # Убираем множественные пробелы
        instr_text = re.sub(r'\s+', ' ', instr_text)
        clean_lines.append(instr_text)

    if valid_count < 2: return ""

    # Pass 2: Rebasing (замена 0x... на INSTR...)
    final_lines = []
    for line in clean_lines:
        def replace_addr(match):
            found = match.group(0)
            if found in addr_to_idx:
                idx = min(addr_to_idx[found], 1023)
                return f"INSTR{idx}"
            return found

        new_line = HEX_PATTERN.sub(replace_addr, line)
        final_lines.append(new_line)

    return "\n".join(final_lines)


def batch_get_embeddings(raw_asm_list):
    """Генерация эмбеддингов батчем"""
    func_dicts = []

    for raw_asm in raw_asm_list:
        if not isinstance(raw_asm, str) or len(raw_asm.strip()) < 5:
            func_dicts.append({"1": "nop"})  # безопасный dummy
            continue

        clean_code = clean_and_rebase(raw_asm)
        lines = clean_code.split('\n')[:MAX_CODE_LEN]

        if len(lines) == 0:
            func_dicts.append({"1": "nop"})
            continue

        func_dict = {str(k): line for k, line in enumerate(lines, start=1)}
        func_dicts.append(func_dict)

    with torch.no_grad():
        encoded = tokenizer(
            func_dicts,
            padding="max_length",
            max_length=MAX_CODE_LEN,
            return_tensors="pt"
        ).to(device)

        outputs = model(**encoded)
        if isinstance(outputs, tuple): 
            outputs = outputs[0]
            
        return outputs.cpu().numpy()


def main():
    print(f"📂 Loading CSV from {INPUT_CSV}...")
    df = pd.read_csv(INPUT_CSV)

    asm_col = "raw_asm"
    print(f"📊 Total functions: {len(df)}")

    all_embeddings = []

    for i in tqdm(range(0, len(df), BATCH_SIZE), desc="CLAP батчи"):
        batch = df[asm_col].iloc[i:i+BATCH_SIZE].tolist()
        batch_emb = batch_get_embeddings(batch)
        all_embeddings.extend(batch_emb)

    df["clap_emb"] = list(map(lambda x: x.tolist(), all_embeddings))
    df.to_csv(OUTPUT_CSV, index=False)

    print(f"✅ Saved to {OUTPUT_CSV}")


if __name__ == "__main__":
    main()