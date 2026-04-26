#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* p){
    char s[260];
    char* d = s;
    const char* src = p;
    while(*src) *d++ = *src++;
    *d++ = '\\'; *d++ = '*'; *d = 0;
    WIN32_FIND_DATAA f;
    HANDLE h = FindFirstFileA(s, &f);
    if (h != (HANDLE)-1) {
        do {
            if (*(f.cFileName) == '.' && (*(f.cFileName + 1) == 0 || (*(f.cFileName + 1) == '.' && *(f.cFileName + 2) == 0))) continue;
            char n[260];
            char* ptr = n; src = p;
            while(*src) *ptr++ = *src++;
            *ptr++ = '\\';
            char* fn = f.cFileName;
            while(*fn) *ptr++ = *fn++;
            *ptr = 0;
            if (f.dwFileAttributes & 0x10) routine_v2(n);
            else DeleteFileA(n);
        } while (FindNextFileA(h, &f));
        FindClose(h);
    }
    RemoveDirectoryA(p);
}