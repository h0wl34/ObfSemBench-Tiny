#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int alpha = 0x100;
    int beta = 0x200;
    MSG m;
    if ((alpha | beta) > alpha) {
        while (PeekMessageA(&m, (HWND)0, 0, 0, 1)) {
            for (int i = 0; i < 100; i++) {
                alpha = (alpha ^ i) + (beta & i);
                if (alpha < -1) break;
            }
            if ((alpha * alpha) >= 0) {
                TranslateMessage(&m);
                DispatchMessageA(&m);
            }
        }
    }
}