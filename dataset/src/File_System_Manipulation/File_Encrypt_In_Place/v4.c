#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* filename, BYTE key){
    int o1 = 15;
    int o2 = 30;
    if ((o1 + o2) == 45) {
        HANDLE h = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (h != INVALID_HANDLE_VALUE) {
            DWORD s = GetFileSize(h, NULL), bR;
            BYTE* b = (BYTE*)LocalAlloc(LPTR, s);
            ReadFile(h, b, s, &bR, NULL);
            for (DWORD i = 0; i < s; i++) {
                if (1) { b[i] = b[i] ^ key; }
                volatile int junk = i * 2;
            }
            SetFilePointer(h, 0, NULL, FILE_BEGIN);
            WriteFile(h, b, s, &bR, NULL);
            LocalFree(b);
            CloseHandle(h);
        }
    }
}