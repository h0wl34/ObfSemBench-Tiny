#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* name, const char* path){
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, name, 0, REG_SZ, (const BYTE*)path, lstrlenA(path) + 1);
        RegCloseKey(hKey);
    }
}