#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(){
    int c = 10;
    while (c--) {
        void* w = (void*)GetForegroundWindow();
        if (w) {
            char t[256];
            char* ptr = t;
            int l = GetWindowTextA((HWND)w, ptr, 255);
            while (l > 0) {
                *(ptr + l) = *(ptr + l - 1);
                l--;
            }
        }
        Sleep(0x3E8);
    }
}