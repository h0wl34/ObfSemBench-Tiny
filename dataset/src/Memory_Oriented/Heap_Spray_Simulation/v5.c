#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(void) {
    HANDLE hHeap = GetProcessHeap();
    int i = 0;
    void *p = NULL;
    int state = 0;
    while (1) {
        switch (state) {
            case 0:
                i = 0;
                state = 1;
                break;
            case 1:
                if (i < 100) {
                    state = 2;
                } else {
                    state = 99;
                }
                break;
            case 2:
                p = HeapAlloc(hHeap, 0, 0x100000);
                state = 3;
                break;
            case 3:
                if (p) {
                    memset(p, 0x90, 0x100000);
                }
                i++;
                state = 1;
                break;
            case 99:
                return;
        }
    }
}