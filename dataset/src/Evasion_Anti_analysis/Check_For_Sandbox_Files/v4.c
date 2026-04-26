#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int v = 0;
    int x = 500;
    if ((x * x) > 0) {
        if (GetFileAttributesA("C:\\windows\\System32\\Drivers\\Vmmouse.sys") != INVALID_FILE_ATTRIBUTES) {
            v = 1;
        }
    }
    for(int j = 0; j < 100; j++) { x += j; }
    if (x > 10) return v;
    return 0;
}