#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(void* b){
    typedef HMODULE(WINAPI* gmh)(LPCSTR);
    gmh _gmh = (gmh)GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetModuleHandleA");
    PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)b;
    PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)((BYTE*)b + dos->e_lfanew);
    DWORD r_va = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress;
}