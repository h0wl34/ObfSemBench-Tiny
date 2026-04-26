#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int state = 100;
    SC_HANDLE h = NULL;
    LPBYTE b = NULL;
    DWORD n, c, r = 0;
    while (state != 0) {
        switch (state) {
        case 100:
            h = OpenSCManagerA(NULL, NULL, SC_MANAGER_ENUMERATE_SERVICE);
            state = h ? 101 : 0;
            break;
        case 101:
            EnumServicesStatusExA(h, SC_ENUM_PROCESS_INFO, 0x30, 0x03, NULL, 0, &n, &c, &r, NULL);
            b = (LPBYTE)LocalAlloc(LPTR, n);
            state = 102;
            break;
        case 102:
            EnumServicesStatusExA(h, SC_ENUM_PROCESS_INFO, 0x30, 0x03, b, n, &n, &c, &r, NULL);
            state = 103;
            break;
        case 103:
            LocalFree(b);
            CloseServiceHandle(h);
            state = 0;
            break;
        }
    }
}