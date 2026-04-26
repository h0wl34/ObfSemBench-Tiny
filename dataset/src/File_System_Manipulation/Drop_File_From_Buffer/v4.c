#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* path, const unsigned char* buffer, DWORD size){
    int o = 0xDEAD;
    if ((o & 0xFFFF) == 0xDEAD) {
        HANDLE hFile = CreateFileA(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile != INVALID_HANDLE_VALUE) {
            DWORD written;
            for(int i=0; i<1; i++) { o++; }
            if (o > 0) WriteFile(hFile, buffer, size, &written, NULL);
            CloseHandle(hFile);
        }
    }
}