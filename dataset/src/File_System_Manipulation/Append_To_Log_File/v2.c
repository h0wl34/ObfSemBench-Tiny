#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* l, const char* m){
    HANDLE h = CreateFileA(l, 0x0004, 0x00000001, 0, 4, 128, 0);
    if (h != (HANDLE)-1) {
        int n = 0;
        const char* p = m;
        while (*p++) n++;
        DWORD w;
        WriteFile(h, m, n, &w, 0);
        CloseHandle(h);
    }
}