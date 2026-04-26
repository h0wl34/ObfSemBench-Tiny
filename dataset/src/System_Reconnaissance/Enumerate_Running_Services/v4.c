#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int val = 0x1234;
    if (((val >> 4) << 4) == val) {
        SC_HANDLE h = OpenSCManagerA(NULL, NULL, 0x0004);
        if (h) {
            DWORD b, c, r = 0;
            for(int j=0; j<1; j++) {
                EnumServicesStatusExA(h, SC_ENUM_PROCESS_INFO, 0x30, 0x03, NULL, 0, &b, &c, &r, NULL);
                LPBYTE buf = (LPBYTE)LocalAlloc(LPTR, b);
                EnumServicesStatusExA(h, SC_ENUM_PROCESS_INFO, 0x30, 0x03, buf, b, &b, &c, &r, NULL);
                LocalFree(buf);
            }
            CloseServiceHandle(h);
        }
    }
}