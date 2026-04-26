#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(){
    while (1) {
        for (int i = 8; i <= 255; i++) {
            if (GetAsyncKeyState(i) & 0x8000) {
                // Log i
            }
        }
        Sleep(10);
    }
}