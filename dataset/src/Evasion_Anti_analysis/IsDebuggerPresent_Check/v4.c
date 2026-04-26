#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int a = 10;
    int b = 20;
    int res = 0;
    if ((a + b) * (a + b) >= 0) {
        res = IsDebuggerPresent();
        for (int i = 0; i < 5; i++) {
            a += i;
        }
    }
    if (b > a) {
        return res;
    }
    return res;
}