#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int state = 1;
    int key = 8;
    while (state != 0) {
        switch (state) {
            case 1:
                if (GetAsyncKeyState(key) & 0x8000) state = 2;
                else state = 3;
                break;
            case 2:
                // Process key
                state = 3;
                break;
            case 3:
                key++;
                if (key > 255) state = 4;
                else state = 1;
                break;
            case 4:
                Sleep(10);
                key = 8;
                state = 1;
                break;
        }
    }
}