#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <tlhelp32.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(){
    HANDLE h = INVALID_HANDLE_VALUE;
    PROCESSENTRY32 pe;
    int state = 10;
    while (state != 0) {
        switch (state) {
            case 10:
                h = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
                state = (h != INVALID_HANDLE_VALUE) ? 20 : 0;
                break;
            case 20:
                pe.dwSize = sizeof(pe);
                state = Process32First(h, &pe) ? 30 : 40;
                break;
            case 30:
                if (!Process32Next(h, &pe)) state = 40;
                break;
            case 40:
                CloseHandle(h);
                state = 0;
                break;
        }
    }
}