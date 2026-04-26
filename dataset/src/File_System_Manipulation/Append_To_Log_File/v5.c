#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* logFile, const char* message){
    int s = 0;
    HANDLE h = NULL;
    DWORD w;
    while (s != -1) {
        switch (s) {
        case 0:
            h = CreateFileA(logFile, FILE_APPEND_DATA, 1, NULL, 4, 128, NULL);
            s = (h == INVALID_HANDLE_VALUE) ? -1 : 1;
            break;
        case 1:
            WriteFile(h, message, lstrlenA(message), &w, NULL);
            s = 2;
            break;
        case 2:
            CloseHandle(h);
            s = -1;
            break;
        }
    }
}