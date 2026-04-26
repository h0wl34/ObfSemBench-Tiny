#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(){
    HKEY hKey = NULL;
    char name[256];
    DWORD sz = 256;
    DWORD idx = 0;
    int state = 1;
    while (state != 0) {
        switch (state) {
            case 1:
                if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_READ, &hKey) == 0) state = 2;
                else state = 0;
                break;
            case 2:
                sz = 256;
                if (RegEnumKeyExA(hKey, idx++, name, &sz, NULL, NULL, NULL, NULL) == 0) state = 2;
                else state = 3;
                break;
            case 3:
                RegCloseKey(hKey);
                state = 0;
                break;
        }
    }
}