#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(){
    HMODULE u32 = LoadLibraryA("user32.dll");
    typedef BOOL(WINAPI* pPM)(LPMSG, HWND, UINT, UINT, UINT);
    typedef BOOL(WINAPI* pTM)(const MSG*);
    typedef LRESULT(WINAPI* pDM)(const MSG*);

    pPM fPM = (pPM)GetProcAddress(u32, "PeekMessageA");
    pTM fTM = (pTM)GetProcAddress(u32, "TranslateMessage");
    pDM fDM = (pDM)GetProcAddress(u32, "DispatchMessageA");

    MSG m;
    if (fPM != NULL) {
        while (fPM(&m, NULL, 0, 0, 1)) {
            fTM(&m);
            fDM(&m);
        }
    }
}