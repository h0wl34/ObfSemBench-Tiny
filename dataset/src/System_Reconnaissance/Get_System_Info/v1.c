#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(SYSTEM_INFO* si){
    GetSystemInfo(si);
}