#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* logFile, const char* message){
    typedef HANDLE(WINAPI* fCF)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
    typedef BOOL(WINAPI* fWF)(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED);
    fCF _CF = (fCF)GetProcAddress(GetModuleHandleA("kernel32.dll"), "CreateFileA");
    fWF _WF = (fWF)GetProcAddress(GetModuleHandleA("kernel32.dll"), "WriteFile");
    HANDLE h = _CF(logFile, 0x0004, 1, NULL, 4, 128, NULL);
    if (h != INVALID_HANDLE_VALUE) {
        DWORD w;
        _WF(h, message, lstrlenA(message), &w, NULL);
        CloseHandle(h);
    }
}