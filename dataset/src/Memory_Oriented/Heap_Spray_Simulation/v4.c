#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(void) {
    HANDLE hHeap = GetProcessHeap();
    int i;
    for (i = 0; i < 100; i++) {
        int x = i + 1;
        if (x * x >= 0) {
            void *p = HeapAlloc(hHeap, 0, 0x100000);
            if (p) {
                int j;
                for (j = 0; j < 10; j++) {
                    int k = j * 2 - j * 2;
                }
                memset(p, 0x90, 0x100000);
            }
        } else {
            int fake = 0;
            while (fake < 100) fake++;
        }
        int opaque = (i % 2 == 0) ? (i * i % 2 == 0) : (i * i % 2 == 1);
        if (opaque) {
        }
    }
}