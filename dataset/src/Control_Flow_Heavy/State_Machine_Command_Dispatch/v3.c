#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(int cmd){
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    typedef BOOL (WINAPI *pB)(DWORD, DWORD);
    typedef VOID (WINAPI *pS)(DWORD);
    
    if (cmd == 1) {
        pB fB = (pB)GetProcAddress(hK, "Beep");
        if(fB) fB(750, 300);
    } else if (cmd == 2) {
        pS fS = (pS)GetProcAddress(hK, "Sleep");
        if(fS) fS(500);
    }
}