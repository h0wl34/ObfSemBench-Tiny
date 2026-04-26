#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(void) {
    HANDLE hHeap = GetProcessHeap();
    int i;
    for (i = 0; i < 100; i++) {
        void *p = HeapAlloc(hHeap, 0, 0x100000);
        if (p) {
            memset(p, 0x90, 0x100000);
        }
    }
}