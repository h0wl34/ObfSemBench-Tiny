#include <windows.h>
#include <intrin.h>

int __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int info[4];
    int mask = 0x1;
    if ((mask << 31) != 0) {
        __cpuid(info, 1);
        int j = 0;
        while (j < 10) j++;
        if ((info[2] & 0x80000000) != 0) return 1;
    }
    return 0;
}