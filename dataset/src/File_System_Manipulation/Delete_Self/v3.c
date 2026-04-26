#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(){
    typedef UINT (WINAPI *WE)(LPCSTR, UINT);
    typedef DWORD (WINAPI *GMFN)(HMODULE, LPSTR, DWORD);
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    WE pWinExec = (WE)GetProcAddress(hK, "WinExec");
    GMFN pGetPath = (GMFN)GetProcAddress(hK, "GetModuleFileNameA");

    char path[MAX_PATH];
    char cmd[MAX_PATH + 50];
    pGetPath(NULL, path, MAX_PATH);
    wsprintfA(cmd, "cmd.exe /c del \"%s\"", path);
    pWinExec(cmd, 0);
}