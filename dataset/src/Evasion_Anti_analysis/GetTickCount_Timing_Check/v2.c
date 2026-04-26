#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v2(int t){
    DWORD s, e;
    DWORD *ps = &s, *pe = &e;
    *ps = GetTickCount();
    for (volatile int i = 0; i < 1000000; i++);
    *pe = GetTickCount();
    if ((*pe - *ps) > (unsigned int)t) return 1;
    return 0;
}