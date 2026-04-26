#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* filename, BYTE key){
    HANDLE hFile = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD size = GetFileSize(hFile, NULL);
        BYTE* buffer = (BYTE*)LocalAlloc(LPTR, size);
        DWORD bytesRead, bytesWritten;
        ReadFile(hFile, buffer, size, &bytesRead, NULL);
        for (DWORD i = 0; i < size; i++) {
            buffer[i] ^= key;
        }
        SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
        WriteFile(hFile, buffer, size, &bytesWritten, NULL);
        LocalFree(buffer);
        CloseHandle(hFile);
    }
}