#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v3(int threshold){
    typedef DWORD (WINAPI *GTC)(VOID);
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    GTC pGetTickCount = (GTC)GetProcAddress(hK, "GetTickCount");
    DWORD s = pGetTickCount();
    for (volatile int i = 0; i < 1000000; i++);
    DWORD e = pGetTickCount();
    return (e - s > (DWORD)threshold);
}