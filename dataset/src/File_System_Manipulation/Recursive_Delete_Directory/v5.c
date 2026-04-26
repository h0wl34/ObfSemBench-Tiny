#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* path){
    int state = 1;
    HANDLE h = INVALID_HANDLE_VALUE;
    WIN32_FIND_DATAA d;
    char s[MAX_PATH];
    while (state != 0) {
        switch (state) {
        case 1:
            wsprintfA(s, "%s\\*", path);
            h = FindFirstFileA(s, &d);
            state = (h == INVALID_HANDLE_VALUE) ? 4 : 2;
            break;
        case 2:
            if (lstrcmpA(d.cFileName, ".") != 0 && lstrcmpA(d.cFileName, "..") != 0) {
                char f[MAX_PATH];
                wsprintfA(f, "%s\\%s", path, d.cFileName);
                if (d.dwFileAttributes & 16) routine_v5(f);
                else DeleteFileA(f);
            }
            state = 3;
            break;
        case 3:
            if (!FindNextFileA(h, &d)) state = 4;
            else state = 2;
            break;
        case 4:
            if (h != INVALID_HANDLE_VALUE) FindClose(h);
            RemoveDirectoryA(path);
            state = 0;
            break;
        }
    }
}