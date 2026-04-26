#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* logFile, const char* message){
    HANDLE hFile = CreateFileA(logFile, FILE_APPEND_DATA, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD written;
        WriteFile(hFile, message, lstrlenA(message), &written, NULL);
        CloseHandle(hFile);
    }
}