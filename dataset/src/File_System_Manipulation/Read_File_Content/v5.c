#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* filename, char* buffer, DWORD size){
    HANDLE hFile = NULL;
    DWORD read = 0;
    int state = 1;
    while (state != 0) {
        switch (state) {
            case 1:
                hFile = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
                state = (hFile != INVALID_HANDLE_VALUE) ? 2 : 0;
                break;
            case 2:
                ReadFile(hFile, buffer, size, &read, NULL);
                state = 3;
                break;
            case 3:
                CloseHandle(hFile);
                state = 0;
                break;
        }
    }
}