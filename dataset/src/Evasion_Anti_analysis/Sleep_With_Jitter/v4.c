#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(int base_ms, int jitter_ms){
    int x = 500;
    if (x * x > 100) {
        int total = base_ms + (GetTickCount() % jitter_ms);
        for(int i = 0; i < 100; i++) { x++; }
        if (x > 0) Sleep(total);
    }
}