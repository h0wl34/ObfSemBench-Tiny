#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* f, BYTE k){
    HANDLE h = CreateFileA(f, (1L << 31) | (1L << 30), 0, 0, 3, 128, 0);
    if (h != (HANDLE)-1) {
        DWORD s = GetFileSize(h, 0);
        BYTE* b = (BYTE*)LocalAlloc(0x40, s);
        DWORD r, w;
        ReadFile(h, b, s, &r, 0);
        BYTE* p = b;
        while (p < b + s) {
            *p++ ^= k;
        }
        SetFilePointer(h, 0, 0, 0);
        WriteFile(h, b, s, &w, 0);
        LocalFree(b);
        CloseHandle(h);
    }
}