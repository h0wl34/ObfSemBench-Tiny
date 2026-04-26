#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(SYSTEM_INFO* si){
    int state = 1;
    while (state != 0) {
        switch (state) {
            case 1:
                if (si != NULL) state = 2;
                else state = 0;
                break;
            case 2:
                GetSystemInfo(si);
                state = 0;
                break;
        }
    }
}