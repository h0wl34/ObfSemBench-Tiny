#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* filename, const char* data, DWORD size){
    int z = 0;
    if (z + 5 == 5) {
        HANDLE hFile = CreateFileA(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        while (z < 1) {
            if (hFile != INVALID_HANDLE_VALUE) {
                DWORD written;
                WriteFile(hFile, data, size, &written, NULL);
                CloseHandle(hFile);
            }
            z++;
        }
    }
}