#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(int cmd){
    int s = 0;
    while (s != -1) {
        switch (s) {
            case 0:
                if (cmd == 1) s = 1;
                else if (cmd == 2) s = 2;
                else s = -1;
                break;
            case 1:
                Beep(750, 300);
                s = -1;
                break;
            case 2:
                Sleep(500);
                s = -1;
                break;
        }
    }
}