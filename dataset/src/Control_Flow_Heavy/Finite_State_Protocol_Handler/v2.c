#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const unsigned char* d, int l){
    int s = 0;
    const unsigned char* p = d;
    while (l--) {
        int m = (*p) & 0xFF;
        s = (s == 0 && m == 0xAA) ? 1 : 
            (s == 1 && m == 0xBB) ? 2 : 
            (s == 2) ? 0 : 0;
        p = (const unsigned char*)((uintptr_t)p + 1);
    }
}