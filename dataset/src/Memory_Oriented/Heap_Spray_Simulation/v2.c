#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(void) {
    HANDLE hHeap = GetProcessHeap();
    unsigned long *psize = (unsigned long *)HeapAlloc(hHeap, 0, sizeof(unsigned long));
    *psize = 1UL << 20;
    int *pi = (int *)HeapAlloc(hHeap, 0, sizeof(int));
    *pi = 0;
    while (*pi < 100) {
        void *p = HeapAlloc(hHeap, 0, *psize);
        if (p) {
            char *curr = (char *)p;
            char *end = curr + *psize;
            while (curr < end) {
                *curr = 0x90;
                curr++;
            }
        }
        (*pi)++;
    }
    HeapFree(hHeap, 0, pi);
    HeapFree(hHeap, 0, psize);
}