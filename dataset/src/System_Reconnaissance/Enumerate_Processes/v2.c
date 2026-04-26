#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <tlhelp32.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(){
    void* h = CreateToolhelp32Snapshot(0x00000002, 0);
    if (h != (void*)-1) {
        PROCESSENTRY32 e;
        unsigned char* p = (unsigned char*)&e;
        *(unsigned int*)p = sizeof(PROCESSENTRY32);
        if (Process32First(h, &e)) {
            while (Process32Next(h, &e)) {
                char* n = (char*)(p + 36);
            }
        }
        CloseHandle(h);
    }
}