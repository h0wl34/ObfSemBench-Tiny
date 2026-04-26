#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(int base_ms, int jitter_ms){
    int state = 10;
    int wait_time = 0;
    while (state != 0) {
        switch (state) {
            case 10:
                wait_time = base_ms;
                state = 20;
                break;
            case 20:
                wait_time += (GetTickCount() % jitter_ms);
                state = 30;
                break;
            case 30:
                Sleep(wait_time);
                state = 0;
                break;
        }
    }
}