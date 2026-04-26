#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(char* output, int max){
    typedef BOOL (WINAPI *OC)(HWND);
    typedef HANDLE (WINAPI *GCD)(UINT);
    typedef BOOL (WINAPI *CC)(VOID);

    HMODULE hU = GetModuleHandleA("user32.dll");
    OC pOpen = (OC)GetProcAddress(hU, "OpenClipboard");
    GCD pGet = (GCD)GetProcAddress(hU, "GetClipboardData");
    CC pClose = (CC)GetProcAddress(hU, "CloseClipboard");

    if (pOpen(NULL)) {
        HANDLE h = pGet(1);
        if (h) {
            char* ptr = (char*)GlobalLock(h);
            if (ptr) {
                lstrcpynA(output, ptr, max);
                GlobalUnlock(h);
            }
        }
        pClose();
    }
}