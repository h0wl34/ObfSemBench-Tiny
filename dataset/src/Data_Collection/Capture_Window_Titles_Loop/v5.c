#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int s = 0;
    int count = 0;
    HWND h = NULL;
    char b[256];
    while (s != -1) {
        switch (s) {
        case 0:
            h = GetForegroundWindow();
            s = (h != NULL) ? 1 : 2;
            break;
        case 1:
            GetWindowTextA(h, b, 256);
            s = 2;
            break;
        case 2:
            Sleep(1000);
            count++;
            s = (count < 10) ? 0 : -1;
            break;
        }
    }
}