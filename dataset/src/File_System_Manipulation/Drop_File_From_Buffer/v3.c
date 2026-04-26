#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* path, const unsigned char* buffer, DWORD size){
    typedef HANDLE (WINAPI *CFA)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
    typedef BOOL (WINAPI *WFA)(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED);
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    CFA pCreate = (CFA)GetProcAddress(hK, "CreateFileA");
    WFA pWrite = (WFA)GetProcAddress(hK, "WriteFile");

    HANDLE h = pCreate(path, 0x40000000L, 0, NULL, 2, 2, NULL);
    if (h != INVALID_HANDLE_VALUE) {
        DWORD w;
        pWrite(h, buffer, size, &w, NULL);
        CloseHandle(h);
    }
}