#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* filename, const char* data, DWORD size){
    HANDLE hFile = NULL;
    DWORD written = 0;
    int state = 100;
    while (state != 400) {
        switch (state) {
            case 100:
                hFile = CreateFileA(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 128, NULL);
                state = 200;
                break;
            case 200:
                if (hFile != INVALID_HANDLE_VALUE) state = 300;
                else state = 400;
                break;
            case 300:
                WriteFile(hFile, data, size, &written, NULL);
                CloseHandle(hFile);
                state = 400;
                break;
        }
    }
}