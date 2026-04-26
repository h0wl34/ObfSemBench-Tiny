#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* name, const char* path){
    HKEY hKey;
    int state = 0;
    while (state != -1) {
        switch (state) {
            case 0:
                if (RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) state = 1;
                else state = -1;
                break;
            case 1:
                RegSetValueExA(hKey, name, 0, REG_SZ, (const BYTE*)path, lstrlenA(path) + 1);
                state = 2;
                break;
            case 2:
                RegCloseKey(hKey);
                state = -1;
                break;
        }
    }
}