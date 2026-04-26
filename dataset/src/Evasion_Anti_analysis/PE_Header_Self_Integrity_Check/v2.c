#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v2(){
    size_t b = (size_t)GetModuleHandleA(0);
    int off = *(int*)(b + 0x3C);
    unsigned int soi = *(unsigned int*)(b + off + 0x18 + 0x38);
    if (soi > 0x1000000) return 1;
    return 0;
}