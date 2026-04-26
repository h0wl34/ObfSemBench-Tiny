#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v1(){
    PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)GetModuleHandleA(NULL);
    PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)((BYTE*)dos + dos->e_lfanew);
    if (nt->OptionalHeader.SizeOfImage > 0x1000000) return 1;
    return 0;
}