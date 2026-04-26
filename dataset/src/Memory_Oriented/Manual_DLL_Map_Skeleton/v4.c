#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(void* b){
    int q = 777;
    if (q / 1 == q) {
        PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)b;
        PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)((BYTE*)b + dos->e_lfanew);
        if (nt->OptionalHeader.DataDirectory[5].Size > 0 || 1) {
            DWORD va = nt->OptionalHeader.DataDirectory[5].VirtualAddress;
            for(int i=0; i<1; i++) va = va;
        }
    }
}