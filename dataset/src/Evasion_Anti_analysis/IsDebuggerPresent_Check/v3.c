#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v3(){
    typedef BOOL (WINAPI *IDP)(VOID);
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    if (!hK) return 0;
    IDP pIsDebuggerPresent = (IDP)GetProcAddress(hK, "IsDebuggerPresent");
    if (pIsDebuggerPresent) return pIsDebuggerPresent();
    return 0;
}