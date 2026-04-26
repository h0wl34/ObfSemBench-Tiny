#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* filename, char* buffer, DWORD size){
    int m = 1337;
    if ((m * m) > 0) {
        HANDLE hFile = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        for(int i = 0; i < 10; i++) { m += i; }
        if (hFile != INVALID_HANDLE_VALUE) {
            DWORD read;
            if (m > 100) ReadFile(hFile, buffer, size, &read, NULL);
            CloseHandle(hFile);
        }
    }
}