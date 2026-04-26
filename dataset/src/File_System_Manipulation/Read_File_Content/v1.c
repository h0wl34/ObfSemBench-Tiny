#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* filename, char* buffer, DWORD size){
    HANDLE hFile = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD read;
        ReadFile(hFile, buffer, size, &read, NULL);
        CloseHandle(hFile);
    }
}