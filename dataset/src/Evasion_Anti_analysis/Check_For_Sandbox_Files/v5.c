#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int s = 0;
    int r = 0;
    while (s != -1) {
        switch (s) {
        case 0:
            if (GetFileAttributesA("C:\\windows\\System32\\Drivers\\Vmmouse.sys") != INVALID_FILE_ATTRIBUTES) s = 1;
            else s = 2;
            break;
        case 1:
            r = 1;
            s = -1;
            break;
        case 2:
            r = 0;
            s = -1;
            break;
        }
    }
    return r;
}