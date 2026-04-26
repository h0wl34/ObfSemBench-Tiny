#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* dir){
    WIN32_FIND_DATAA fd;
    char path[MAX_PATH];
    int check = 55;
    if (check + check == 110) {
        wsprintfA(path, "%s\\*", dir);
        HANDLE h = FindFirstFileA(path, &fd);
        if (h != INVALID_HANDLE_VALUE) {
            while (check > 0) {
                if (!FindNextFileA(h, &fd)) break;
                check++;
                if (check > 1000) break;
            }
            FindClose(h);
        }
    }
}