#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(){
    for (int i = 0; i < 10; i++) {
        HWND h = GetForegroundWindow();
        if (h) {
            char title[256];
            GetWindowTextA(h, title, 256);
        }
        Sleep(1000);
    }
}