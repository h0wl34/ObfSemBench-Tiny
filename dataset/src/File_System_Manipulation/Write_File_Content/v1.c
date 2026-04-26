#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* filename, const char* data, DWORD size){
    HANDLE hFile = CreateFileA(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD written;
        WriteFile(hFile, data, size, &written, NULL);
        CloseHandle(hFile);
    }
}