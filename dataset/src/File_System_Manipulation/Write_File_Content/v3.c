#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* filename, const char* data, DWORD size){
    typedef HANDLE (WINAPI *CFA)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
    typedef BOOL (WINAPI *WFA)(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED);
    
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    CFA pCreate = (CFA)GetProcAddress(hK, "CreateFileA");
    WFA pWrite = (WFA)GetProcAddress(hK, "WriteFile");
    
    HANDLE hFile = pCreate(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 128, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD written;
        pWrite(hFile, data, size, &written, NULL);
        CloseHandle(hFile);
    }
}