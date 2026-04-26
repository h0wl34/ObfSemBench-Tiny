#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(void* b){
    int s = 0;
    PIMAGE_NT_HEADERS nt = NULL;
    while (s != -1) {
        switch (s) {
            case 0:
                nt = (PIMAGE_NT_HEADERS)((BYTE*)b + ((PIMAGE_DOS_HEADER)b)->e_lfanew);
                s = 1;
                break;
            case 1:
                if (nt->OptionalHeader.DataDirectory[5].VirtualAddress != 0) s = 2;
                else s = -1;
                break;
            case 2:
                s = -1;
                break;
        }
    }
}