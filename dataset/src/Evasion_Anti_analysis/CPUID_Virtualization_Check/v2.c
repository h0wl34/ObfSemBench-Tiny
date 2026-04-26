#include <windows.h>
#include <intrin.h>

int __attribute__((noinline)) __attribute__((used)) routine_v2(){
    int info[4];
    int* p = info;
    __cpuid(info, 1);
    return (*(p + 2) & 0x80000000) != 0;
}