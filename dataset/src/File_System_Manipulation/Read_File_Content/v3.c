#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* filename, char* buffer, DWORD size){
    typedef HANDLE (WINAPI *CFA)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
    typedef BOOL (WINAPI *RFA)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED);
    typedef BOOL (WINAPI *CH)(HANDLE);

    HMODULE hK = GetModuleHandleA("kernel32.dll");
    CFA pCreate = (CFA)GetProcAddress(hK, "CreateFileA");
    RFA pRead = (RFA)GetProcAddress(hK, "ReadFile");
    CH pClose = (CH)GetProcAddress(hK, "CloseHandle");

    HANDLE hFile = pCreate(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD read;
        pRead(hFile, buffer, size, &read, NULL);
        pClose(hFile);
    }
}