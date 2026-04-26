#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* f, BYTE k){
    int state = 0;
    HANDLE h = NULL;
    BYTE* b = NULL;
    DWORD s = 0, br = 0;
    while (state != -1) {
        switch (state) {
        case 0:
            h = CreateFileA(f, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
            state = (h == INVALID_HANDLE_VALUE) ? -1 : 1;
            break;
        case 1:
            s = GetFileSize(h, NULL);
            b = (BYTE*)LocalAlloc(LPTR, s);
            ReadFile(h, b, s, &br, NULL);
            state = 2;
            break;
        case 2:
            for (DWORD i = 0; i < s; i++) b[i] ^= k;
            state = 3;
            break;
        case 3:
            SetFilePointer(h, 0, NULL, FILE_BEGIN);
            WriteFile(h, b, s, &br, NULL);
            state = 4;
            break;
        case 4:
            LocalFree(b);
            CloseHandle(h);
            state = -1;
            break;
        }
    }
}