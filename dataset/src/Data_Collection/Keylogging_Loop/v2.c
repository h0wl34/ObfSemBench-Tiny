#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(){
    short s;
    short* ps = &s;
    int i;
    int* pi = &i;
    while (1) {
        *pi = 8;
        while (*pi <= 255) {
            *ps = GetAsyncKeyState(*pi);
            if ((*ps >> 15) & 1) {
                char k = (char)*pi;
            }
            (*pi)++;
        }
        Sleep(10);
    }
}