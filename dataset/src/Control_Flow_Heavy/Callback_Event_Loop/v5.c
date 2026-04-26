#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int state = 0;
    MSG m;
    while (state != -1) {
        switch (state) {
        case 0:
            state = PeekMessageA(&m, NULL, 0, 0, 1) ? 1 : -1;
            break;
        case 1:
            TranslateMessage(&m);
            state = 2;
            break;
        case 2:
            DispatchMessageA(&m);
            state = 0;
            break;
        default:
            state = -1;
            break;
        }
    }
}