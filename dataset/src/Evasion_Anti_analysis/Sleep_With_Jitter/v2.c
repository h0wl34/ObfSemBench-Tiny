#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(int b, int j){
    int t;
    int* p = &t;
    unsigned int r;
    unsigned int* pr = &r;
    static unsigned int seed = 0x1234;
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    *pr = seed;
    *p = b + (*pr % j);
    Sleep(*p);
}