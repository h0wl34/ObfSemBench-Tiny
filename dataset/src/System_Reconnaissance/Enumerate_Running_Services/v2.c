#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(){
    SC_HANDLE h = OpenSCManagerA(0, 0, 0x0004);
    if (h) {
        DWORD n = 0, c = 0, r = 0;
        EnumServicesStatusExA(h, 0, 0x30, 0x03, 0, 0, &n, &c, &r, 0);
        void* b = LocalAlloc(0x40, n);
        if (EnumServicesStatusExA(h, 0, 0x30, 0x03, (LPBYTE)b, n, &n, &c, &r, 0)) {
            unsigned char* p = (unsigned char*)b;
            for (DWORD i = 0; i < c; i++) {
                char* s = *(char**)(p + (i * (sizeof(size_t) * 2 + sizeof(SERVICE_STATUS_PROCESS))));
            }
        }
        LocalFree(b);
        CloseServiceHandle(h);
    }
}