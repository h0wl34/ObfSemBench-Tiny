#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v1(int threshold){
    DWORD start = GetTickCount();
    for (int i = 0; i < 1000000; i++);
    DWORD end = GetTickCount();
    if ((end - start) > (DWORD)threshold) return 1;
    return 0;
}