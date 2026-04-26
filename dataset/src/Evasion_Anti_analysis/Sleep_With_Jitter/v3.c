#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(int base_ms, int jitter_ms){
    typedef VOID (WINAPI *SLP)(DWORD);
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    SLP pSleep = (SLP)GetProcAddress(hK, "Sleep");
    int total = base_ms + (GetTickCount() % jitter_ms);
    if (pSleep) pSleep(total);
}