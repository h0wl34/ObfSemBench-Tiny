#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v3(){
    typedef HMODULE(WINAPI* fGMH)(LPCSTR);
    fGMH _GMH = (fGMH)GetProcAddress(LoadLibraryA("kernel32.dll"), "GetModuleHandleA");
    unsigned char* b = (unsigned char*)_GMH(NULL);
    DWORD l = *(DWORD*)(b + 0x3C);
    if (*(DWORD*)(b + l + 0x50) > 0x1000000) return 1;
    return 0;
}