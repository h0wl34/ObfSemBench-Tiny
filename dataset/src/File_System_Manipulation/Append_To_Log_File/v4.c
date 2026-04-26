#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* logFile, const char* message){
    int a = 100;
    int b = 200;
    if (b > a) {
        HANDLE h = CreateFileA(logFile, FILE_APPEND_DATA, 1, NULL, 4, 128, NULL);
        if (h != INVALID_HANDLE_VALUE) {
            for (int i = 0; i < 1; i++) {
                DWORD w;
                WriteFile(h, message, lstrlenA(message), &w, NULL);
            }
            CloseHandle(h);
        }
    }
}