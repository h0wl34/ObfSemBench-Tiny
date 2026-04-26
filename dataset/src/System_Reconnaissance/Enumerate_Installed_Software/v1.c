#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(){
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        char subKeyName[256];
        DWORD nameSize = 256;
        for (DWORD i = 0; RegEnumKeyExA(hKey, i, subKeyName, &nameSize, NULL, NULL, NULL, NULL) == ERROR_SUCCESS; i++) {
            nameSize = 256;
        }
        RegCloseKey(hKey);
    }
}