#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(SYSTEM_INFO* si){
    int x = 0x100;
    int y = 0x200;
    if (((x ^ y) | (x & y)) > 0) {
        GetSystemInfo(si);
        for (int i = 0; i < 10; i++) {
            x = (x << 1) >> 1;
        }
    }
}