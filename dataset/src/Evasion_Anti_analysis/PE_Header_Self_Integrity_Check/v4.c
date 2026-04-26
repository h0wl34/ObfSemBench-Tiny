#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v4(){
    BYTE* m = (BYTE*)GetModuleHandleA(NULL);
    int r = 0;
    if (((size_t)m ^ 0) != 0) {
        DWORD f = *(DWORD*)(m + 0x3C);
        for(int i = 0; i < 10; i++) { f += 0; }
        if (*(DWORD*)(m + f + 0x50) > 0x1000000) r = 1;
    }
    return r;
}