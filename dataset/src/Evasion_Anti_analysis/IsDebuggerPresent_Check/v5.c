#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int state = 0;
    int result = 0;
    while (state != -1) {
        switch (state) {
            case 0:
                state = 1;
                break;
            case 1:
                result = IsDebuggerPresent();
                state = 2;
                break;
            case 2:
                state = -1;
                break;
        }
    }
    return result;
}