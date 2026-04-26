#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(){
    HKEY hKey;
    int a = 7;
    int b = 14;
    if ((b / a) == 2) {
        if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
            char buf[256];
            DWORD sz = 256;
            for (DWORD i = 0; i < 500; i++) {
                if (RegEnumKeyExA(hKey, i, buf, &sz, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
                sz = 256;
                a++;
            }
            RegCloseKey(hKey);
        }
    }
}