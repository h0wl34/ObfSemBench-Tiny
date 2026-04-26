#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int s = 0;
    BYTE* b = NULL;
    DWORD f = 0;
    int res = 0;
    while (s != -1) {
        switch (s) {
        case 0:
            b = (BYTE*)GetModuleHandleA(NULL);
            s = 1;
            break;
        case 1:
            f = *(DWORD*)(b + 0x3C);
            s = 2;
            break;
        case 2:
            if (*(DWORD*)(b + f + 0x50) > 0x1000000) res = 1;
            s = -1;
            break;
        }
    }
    return res;
}