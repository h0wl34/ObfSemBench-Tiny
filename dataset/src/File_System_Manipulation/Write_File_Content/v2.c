#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* f, const char* d, unsigned int s){
    void* h = CreateFileA(f, 0x40000000L, 0, 0, 2, 0x00000080, 0);
    if (h != (void*)-1) {
        unsigned long w;
        unsigned long* pw = &w;
        const char* pd = d;
        WriteFile(h, (const void*)pd, s, pw, 0);
        CloseHandle(h);
    }
}