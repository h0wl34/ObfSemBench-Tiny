#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(int c){
    void* base = &c;
    int val = *(int*)base;
    void (*funcs[4])(DWORD, DWORD);
    funcs[0] = (void (*)(DWORD, DWORD))Beep;
    funcs[1] = (void (*)(DWORD, DWORD))Sleep;
    
    if (((val >> 1) << 1) == val) {
        unsigned char* p = (unsigned char*)base;
        *p = *p ^ 0xFF;
    }

    if (val == 1) {
        ((void(*)(DWORD, DWORD))((char*)funcs[0]))(750, 300);
    } else if (val == 2) {
        ((void(*)(DWORD))((char*)funcs[1]))(500);
    }
}