#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* dir){
    WIN32_FIND_DATAA fd;
    char path[MAX_PATH];
    HANDLE h = INVALID_HANDLE_VALUE;
    int state = 1;
    while (state != 0) {
        switch (state) {
            case 1:
                wsprintfA(path, "%s\\*", dir);
                h = FindFirstFileA(path, &fd);
                state = (h != INVALID_HANDLE_VALUE) ? 2 : 0;
                break;
            case 2:
                if (FindNextFileA(h, &fd)) state = 2;
                else state = 3;
                break;
            case 3:
                FindClose(h);
                state = 0;
                break;
        }
    }
}