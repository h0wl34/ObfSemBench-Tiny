#include <windows.h>

FARPROC __attribute__((noinline)) __attribute__((used)) routine_v1(HMODULE hMod, DWORD targetHash){
    PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)hMod;
    PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)((BYTE*)hMod + dos->e_lfanew);
    PIMAGE_EXPORT_DIRECTORY exp = (PIMAGE_EXPORT_DIRECTORY)((BYTE*)hMod + nt->OptionalHeader.DataDirectory[0].VirtualAddress);
    DWORD* names = (DWORD*)((BYTE*)hMod + exp->AddressOfNames);
    for (DWORD i = 0; i < exp->NumberOfNames; i++) {
        char* name = (char*)((BYTE*)hMod + names[i]);
        DWORD h = 0;
        while (*name) h = ((h << 5) | (h >> 27)) + *name++;
        if (h == targetHash) {
            WORD* ords = (WORD*)((BYTE*)hMod + exp->AddressOfNameOrdinals);
            DWORD* acts = (DWORD*)((BYTE*)hMod + exp->AddressOfFunctions);
            return (FARPROC)((BYTE*)hMod + acts[ords[i]]);
        }
    }
    return NULL;
}