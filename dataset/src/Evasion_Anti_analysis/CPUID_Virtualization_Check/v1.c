#include <windows.h>
#include <intrin.h>

int __attribute__((noinline)) __attribute__((used)) routine_v1(){
    int cpuInfo[4];
    __cpuid(cpuInfo, 1);
    if ((cpuInfo[2] >> 31) & 1) return 1;
    return 0;
}