#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(){
    typedef LSTATUS (WINAPI *ROKEA)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY);
    typedef LSTATUS (WINAPI *REKEA)(HKEY, DWORD, LPSTR, LPDWORD, LPDWORD, LPSTR, LPDWORD, PFILETIME);

    HMODULE hA = LoadLibraryA("advapi32.dll");
    ROKEA fOpen = (ROKEA)GetProcAddress(hA, "RegOpenKeyExA");
    REKEA fEnum = (REKEA)GetProcAddress(hA, "RegEnumKeyExA");

    HKEY hKey;
    if (fOpen(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_READ, &hKey) == 0) {
        char name[256];
        DWORD sz = 256;
        DWORD idx = 0;
        while (fEnum(hKey, idx++, name, &sz, NULL, NULL, NULL, NULL) == 0) {
            sz = 256;
        }
        RegCloseKey(hKey);
    }
}