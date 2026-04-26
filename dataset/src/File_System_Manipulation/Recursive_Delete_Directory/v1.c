#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* path){
    char searchPath[MAX_PATH];
    wsprintfA(searchPath, "%s\\*", path);
    WIN32_FIND_DATAA data;
    HANDLE hFind = FindFirstFileA(searchPath, &data);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (lstrcmpA(data.cFileName, ".") != 0 && lstrcmpA(data.cFileName, "..") != 0) {
                char fullPath[MAX_PATH];
                wsprintfA(fullPath, "%s\\%s", path, data.cFileName);
                if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) routine_v1(fullPath);
                else DeleteFileA(fullPath);
            }
        } while (FindNextFileA(hFind, &data));
        FindClose(hFind);
    }
    RemoveDirectoryA(path);
}