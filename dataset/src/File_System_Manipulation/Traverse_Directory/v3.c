#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* dir){
    typedef HANDLE (WINAPI *FFF)(LPCSTR, LPWIN32_FIND_DATAA);
    typedef BOOL (WINAPI *FNF)(HANDLE, LPWIN32_FIND_DATAA);
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    FFF pFirst = (FFF)GetProcAddress(hK, "FindFirstFileA");
    FNF pNext = (FNF)GetProcAddress(hK, "FindNextFileA");

    WIN32_FIND_DATAA fd;
    char path[MAX_PATH];
    wsprintfA(path, "%s\\*", dir);
    HANDLE h = pFirst(path, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            char* n = fd.cFileName;
        } while (pNext(h, &fd));
        FindClose(h);
    }
}