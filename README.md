# 🦠 ObfSemBench-Tiny: A Tiny Semantics Benchmark for Obfuscated Binary Code Analysis

[![Dataset on HuggingFace](https://img.shields.io/badge/%F0%9F%A4%97%20Datasets-Available-orange)](https://huggingface.co/datasets/herb4r/ObfSemBench)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

**ObfSemBench-Tiny** is a tiny synthetic C-code benchmark designed to evaluate AI models on **binary code semantic search**, **malware behavior retrieval**, and **robustness against compilation optimizations and algorithmic obfuscation**.

While compact in size (1088 carefully generated functions), it provides a rigorous testing ground by avoiding the noise of real-world malware datasets and offering clean, function-level Ground Truth across 78 specific behaviors and 5 levels of structural obfuscation.

---

## 🎯 Why This Benchmark?

Evaluating Large Language Models (LLMs) and Code Encoders (like CLAP-ASM, Trex, or jTrans) on binary code is challenging due to the lack of parallel "Source-to-Binary" datasets with controlled obfuscation. 

This dataset solves three major challenges:
1. **Controlled Obfuscation (V1-V5):** Each behavior is implemented in 5 distinct variations, ranging from naive code to OLLVM-style Control Flow Flattening.
2. **Compiler DCE Evasion:** All C codes are strictly prompted to bypass GCC's Dead Code Elimination (DCE) even under `-O2` and `-Os` flags, utilizing `volatile` pointers and forced side-effects.
3. **Unlinked API Recovery:** Includes a custom `objdump -r` relocation patching pipeline to recover `__imp_` API calls in unlinked `.o` object files, preserving network and filesystem semantics for static analysis.

---

## 🧬 Taxonomy & Obfuscation Levels

The dataset covers **8 Macro-categories** (e.g., *Cryptographic*, *Network_Communication*, *Evasion*, *Persistence*) and **78 specific micro-behaviors** (e.g., `Reverse_TCP_Connect`, `IsDebuggerPresent_Check`).

Each malicious behavior is implemented across 5 variations:
*   **V1 (Naive):** Standard implementation with direct API calls and clear arrays.
*   **V2 (Pointer Arithmetic):** Heavily relies on pointers and bitwise shifts instead of standard structs.
*   **V3 (Dynamic API):** Zero direct WinAPI calls. Resolves all external functions at runtime via `LoadLibrary` and `GetProcAddress`.
*   **V4 (Junk Code):** Injects opaque predicates (e.g., `if (x*x >= 0)`) and dead math loops.
*   **V5 (Control Flow Flattening):** Encases the entire logic in a state-machine `switch-case` block inside an infinite loop.

---

## 📊 Dataset Structure

The benchmark provides the source `.c` files, the extracted raw assembly, the cleaned/rebased assembly, and the pre-computed **CLAP-ASM (768-dim)** embeddings.

*The full pre-computed CSV is hosted on HuggingFace:*  
👉 **[HuggingFace Dataset: ObfSemBench](https://huggingface.co/datasets/herb4r/ObfSemBench)**

### Data Format
| Column | Description |
| :--- | :--- |
| `category` | Macro-behavior (e.g., `Evasion_Anti_analysis`) |
| `behavior` | Specific intent (e.g., `Sleep_With_Jitter`) |
| `obfuscation`| Variation level (`V1` to `V5`) |
| `compiler` | GCC flags used (`gcc_O0`, `gcc_O2`, `gcc_Os`) |
| `raw_asm` | Raw objdump assembly (with resolved relocations) |
| `clap_emb` | 768-dimensional semantic embedding (NumPy array) |

---

## Prerequisites

Because this benchmark generates and compiles code targeting the Windows API (using `<windows.h>`, `<winsock2.h>`, etc.), you must have a compatible compiler installed.

### System Requirements
*   **Python 3.10+**
*   **If on Windows:** MinGW-w64 installed and added to your system `PATH` (both `gcc` and `objdump` must be accessible).
*   **If on Linux:** Cross-compilation toolchain is required. You must install `mingw-w64` and `binutils-mingw-w64`.
    ```bash
    sudo apt-get update
    sudo apt-get install mingw-w64 binutils-mingw-w64
    ```
    *(Note: If using Linux, you may need to modify the compiler calls in `scripts/01_compile_and_extract.py` from `gcc` to `x86_64-w64-mingw32-gcc` and `objdump` to `x86_64-w64-mingw32-objdump`).*

---

## 🚀 Getting Started 

### 1. Reproducing the Compilation & Extraction

To re-compile the C sources from scratch and extract the assembly using the provided scripts:
```bash
pip install -r requirements.txt
python scripts/01_compile_and_extract.py && python scripts/02_patch_sources.py
```

This script will compile the `.c` files into unlinked `.o` object files using `-O0`, `-O2`, and `-Os` flags, and then extract the raw assembly.

### 2. Generating Embeddings
To generate the 768-dimensional CLAP-ASM embeddings:
```bash
python scripts/03_generate_embeddings.py
```

### 3. Evaluating Your Own Model
Check the `notebooks/` folder for the evaluation scripts. You can swap the CLAP-ASM embeddings with your own model's embeddings to calculate Recall@K and Mean Average Precision (MAP) against the benchmark.

---

## 📈 Evaluation Results (CLAP-ASM Baseline)

We provide baseline evaluation metrics using [CLAP-ASM](https://github.com/Hustcw/CLAP).
*   **Text-to-ASM Recall@5:** `60.26%`
*   **Aggressive Macro-Behavior Recall@5:** `69.23%`
*   **ASM-to-ASM Clone Detection (Recall@1):** `78.68%`

*For full robustness breakdown (Easy vs. Hard Code) and Prompt Sensitivity analysis, see the evaluation notebooks.*

---

## 📖 Citation / Academic Context

This benchmark was created as part of research on neuro-symbolic malware triage and concept drift mitigation. 
If you use this benchmark in your research, please refer to the associated thesis/paper (Details TBA).
