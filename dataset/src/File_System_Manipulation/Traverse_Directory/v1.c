#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* dir){
    WIN32_FIND_DATAA findData;
    char searchPath[MAX_PATH];
    wsprintfA(searchPath, "%s\\*", dir);
    HANDLE hFind = FindFirstFileA(searchPath, &findData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                // Logic per file
            }
        } while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }
}