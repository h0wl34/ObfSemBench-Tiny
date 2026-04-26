#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(int* context) {
    int state = 0x10;
    int running = 1;
    void* dispatcher[4];

    while (running) {
        switch (state) {
            case 0x10:
                *context += 5;
                state = 0x25;
                break;
            case 0x25:
                if (*context % 2 == 0) {
                    state = 0x30;
                } else {
                    state = 0x35;
                }
                break;
            case 0x30:
                *context /= 2;
                state = 0x40;
                break;
            case 0x35:
                *context = (*context * 3) + 1;
                state = 0x40;
                break;
            case 0x40:
                for (int i = 0; i < 2; i++) {
                    *context ^= 0xFF;
                }
                state = 0x50;
                break;
            case 0x50:
                running = 0;
                break;
            default:
                state = 0x50;
                break;
        }
    }
}