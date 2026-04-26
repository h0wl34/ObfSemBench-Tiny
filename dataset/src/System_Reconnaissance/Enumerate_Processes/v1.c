#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <tlhelp32.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(){
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);
        if (Process32First(hSnap, &pe)) {
            do {
                // Process name: pe.szExeFile
            } while (Process32Next(hSnap, &pe));
        }
        CloseHandle(hSnap);
    }
}