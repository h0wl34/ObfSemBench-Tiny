#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(){
    typedef SHORT (WINAPI *GAKS)(int);
    HMODULE hU = GetModuleHandleA("user32.dll");
    GAKS pState = (GAKS)GetProcAddress(hU, "GetAsyncKeyState");
    
    if (pState) {
        while (1) {
            for (int i = 8; i <= 255; i++) {
                if (pState(i) & 0x8000) {}
            }
            Sleep(10);
        }
    }
}