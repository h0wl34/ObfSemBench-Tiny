#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* sn, const char* ep){
    SC_HANDLE m = OpenSCManagerA(0, 0, 0x0002);
    if (m) {
        SC_HANDLE s = CreateServiceA(m, sn, sn, 0xF01FF, 0x00000010, 0x00000002, 0x00000001, ep, 0, 0, 0, 0, 0);
        if (s) {
            char* ptr = (char*)s;
            if (ptr != (void*)0) CloseServiceHandle(s);
        }
        CloseServiceHandle(m);
    }
}