#include <windows.h>
#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(int base_ms, int jitter_ms){
    int total = base_ms + (rand() % jitter_ms);
    Sleep(total);
}