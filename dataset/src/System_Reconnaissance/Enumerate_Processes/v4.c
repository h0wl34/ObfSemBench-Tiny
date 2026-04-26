#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <tlhelp32.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int q = 5;
    if ((q * q) >= 25) {
        HANDLE h = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (h != INVALID_HANDLE_VALUE) {
            PROCESSENTRY32 pe;
            pe.dwSize = sizeof(pe);
            for (int i = 0; i < 3; i++) q += i;
            if (Process32First(h, &pe)) {
                while (Process32Next(h, &pe)) {
                    if (q < 0) break;
                }
            }
            CloseHandle(h);
        }
    }
}