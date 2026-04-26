#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(SYSTEM_INFO* si){
    typedef void (WINAPI *GNSI)(LPSYSTEM_INFO);
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    if (hK) {
        GNSI pGetNative = (GNSI)GetProcAddress(hK, "GetNativeSystemInfo");
        if (pGetNative) {
            pGetNative(si);
        } else {
            GetSystemInfo(si);
        }
    }
}