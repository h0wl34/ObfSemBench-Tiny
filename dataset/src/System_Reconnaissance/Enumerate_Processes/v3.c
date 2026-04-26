#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <tlhelp32.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(){
    typedef HANDLE (WINAPI *CT32S)(DWORD, DWORD);
    typedef BOOL (WINAPI *P32F)(HANDLE, LPPROCESSENTRY32);
    typedef BOOL (WINAPI *P32N)(HANDLE, LPPROCESSENTRY32);

    HMODULE hK = GetModuleHandleA("kernel32.dll");
    CT32S fSnap = (CT32S)GetProcAddress(hK, "CreateToolhelp32Snapshot");
    P32F fFirst = (P32F)GetProcAddress(hK, "Process32FirstA");
    P32N fNext = (P32N)GetProcAddress(hK, "Process32NextA");

    HANDLE h = fSnap(TH32CS_SNAPPROCESS, 0);
    if (h != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(pe);
        if (fFirst(h, &pe)) {
            while (fNext(h, &pe));
        }
        CloseHandle(h);
    }
}