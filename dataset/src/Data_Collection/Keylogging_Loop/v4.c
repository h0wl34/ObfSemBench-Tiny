#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int junk = 99;
    while (junk > 0) {
        if ((junk * junk) >= 0) {
            for (int i = 8; i <= 255; i++) {
                if (GetAsyncKeyState(i) & 0x8000) {
                    for(int j=0; j<2; j++) junk++;
                }
            }
        }
        Sleep(10);
        junk--;
        if (junk < 5) junk = 99;
    }
}