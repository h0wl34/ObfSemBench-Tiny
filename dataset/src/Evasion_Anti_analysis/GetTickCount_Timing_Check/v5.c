#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v5(int threshold){
    DWORD t1, t2;
    int state = 1;
    int result = 0;
    while (state != 0) {
        switch (state) {
            case 1:
                t1 = GetTickCount();
                state = 2;
                break;
            case 2:
                for (volatile int i = 0; i < 1000000; i++);
                state = 3;
                break;
            case 3:
                t2 = GetTickCount();
                state = 4;
                break;
            case 4:
                result = (t2 - t1 > (DWORD)threshold);
                state = 0;
                break;
        }
    }
    return result;
}