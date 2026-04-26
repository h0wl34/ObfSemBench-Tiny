#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* f, char* b, unsigned int s){
    void* h = CreateFileA(f, (unsigned int)0x80000000L, 0x00000001, 0, 3, 0x80, 0);
    if (h != (void*)-1) {
        unsigned long r;
        unsigned long* pr = &r;
        char* pb = b;
        ReadFile(h, pb, s, pr, 0);
        CloseHandle(h);
    }
}