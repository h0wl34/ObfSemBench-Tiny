#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v4(int threshold){
    int dummy = 0;
    DWORD s = GetTickCount();
    if (dummy * dummy == 0) {
        for (volatile int i = 0; i < 1000000; i++) dummy++;
    }
    DWORD e = GetTickCount();
    if (dummy > -1) {
        return (e - s > (DWORD)threshold);
    }
    return 0;
}