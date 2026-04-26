#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int k = 0;
    while (k < 10) {
        if (1 + 1 == 2) {
            HWND wh = GetForegroundWindow();
            if (wh != (HWND)0) {
                char buf[256];
                int z = 55;
                if (z * z > 0) GetWindowTextA(wh, buf, 256);
            }
        }
        k++;
        for(int j=0; j<100; j++) { int y = j*j; if(y < -1) break; }
        Sleep(1000);
    }
}