#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v3(){
    typedef void (WINAPI *GSI)(LPSYSTEM_INFO);
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    GSI pGetSystemInfo = (GSI)GetProcAddress(hK, "GetSystemInfo");
    SYSTEM_INFO si;
    if (pGetSystemInfo) pGetSystemInfo(&si);
    if (si.dwNumberOfProcessors < 2) return 1;
    return 0;
}