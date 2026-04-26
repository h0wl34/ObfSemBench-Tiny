#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* p, const unsigned char* b, unsigned int s){
    void* h = CreateFileA(p, 0x40000000L, 0, 0, 2, 0x00000002, 0);
    if (h != (void*)-1) {
        unsigned long w;
        const unsigned char* pb = b;
        unsigned int i = 0;
        WriteFile(h, (const void*)pb, s, &w, 0);
        CloseHandle(h);
    }
}