#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v3(){
    typedef DWORD(WINAPI* fGFA)(LPCSTR);
    HMODULE hK = LoadLibraryA("kernel32.dll");
    fGFA _GFA = (fGFA)GetProcAddress(hK, "GetFileAttributesA");
    if (_GFA("C:\\windows\\System32\\Drivers\\Vmmouse.sys") != INVALID_FILE_ATTRIBUTES) return 1;
    return 0;
}