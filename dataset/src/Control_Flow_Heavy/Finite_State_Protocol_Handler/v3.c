#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const unsigned char* data, int len){
    typedef void (WINAPI *pODS)(LPCSTR);
    pODS fODS = (pODS)GetProcAddress(GetModuleHandleA("kernel32.dll"), "OutputDebugStringA");
    int state = 0;
    for (int i = 0; i < len; i++) {
        if (state == 0 && data[i] == 0xAA) {
            state = 1;
            if(fODS) fODS("S1");
        } else if (state == 1 && data[i] == 0xBB) {
            state = 2;
            if(fODS) fODS("S2");
        } else {
            state = 0;
        }
    }
}