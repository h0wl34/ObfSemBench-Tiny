#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* d){
    WIN32_FIND_DATAA f;
    char p[260];
    char* ptr = p;
    while(*d) *ptr++ = *d++;
    *ptr++ = '\\'; *ptr++ = '*'; *ptr = 0;
    void* h = FindFirstFileA(p, &f);
    if (h != (void*)-1) {
        unsigned int* pa = (unsigned int*)&f;
        do {
            if (!(*pa & 0x10)) {
                char* name = f.cFileName;
            }
        } while (FindNextFileA(h, &f));
        FindClose(h);
    }
}