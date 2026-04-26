#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* path, const unsigned char* buffer, DWORD size){
    HANDLE hFile = CreateFileA(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD written;
        WriteFile(hFile, buffer, size, &written, NULL);
        CloseHandle(hFile);
    }
}