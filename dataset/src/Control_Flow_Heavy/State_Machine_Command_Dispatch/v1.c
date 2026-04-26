#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(int cmd){
    int state = 0;
    switch (cmd) {
        case 1:
            state = 100;
            Beep(750, 300);
            break;
        case 2:
            state = 200;
            Sleep(500);
            break;
        case 3:
            state = 300;
            ExitProcess(0);
            break;
        default:
            state = 0;
            break;
    }
}