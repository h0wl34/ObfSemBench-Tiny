#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* path, const unsigned char* buffer, DWORD size){
    HANDLE h = NULL;
    DWORD w = 0;
    int state = 1;
    while (state != 0) {
        switch (state) {
            case 1:
                h = CreateFileA(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
                state = (h != INVALID_HANDLE_VALUE) ? 2 : 0;
                break;
            case 2:
                WriteFile(h, buffer, size, &w, NULL);
                state = 3;
                break;
            case 3:
                CloseHandle(h);
                state = 0;
                break;
        }
    }
}