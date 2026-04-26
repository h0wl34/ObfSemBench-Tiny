#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(int cmd){
    int x = 5;
    int y = 10;
    if ((x * x + y * y) > 0) {
        if (cmd == 1) {
            for(int i = 0; i < 10; i++) { x += i; }
            Beep(750, 300);
        } else if (cmd == 2) {
            if (y > x || x > y) {
                Sleep(500);
            }
        }
    }
}