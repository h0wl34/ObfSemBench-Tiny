#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(){
    typedef HWND(WINAPI* pGFW)();
    typedef int(WINAPI* pGWT)(HWND, LPSTR, int);
    HMODULE u32 = LoadLibraryA("user32.dll");
    pGFW _GFW = (pGFW)GetProcAddress(u32, "GetForegroundWindow");
    pGWT _GWT = (pGWT)GetProcAddress(u32, "GetWindowTextA");
    for (int i = 0; i < 5; i++) {
        HWND h = _GFW();
        if (h) {
            char b[128];
            _GWT(h, b, 128);
        }
        Sleep(500);
    }
}