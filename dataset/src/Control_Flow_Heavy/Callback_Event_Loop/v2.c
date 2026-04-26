#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(){
    char m_raw[sizeof(MSG)];
    void* p_m = (void*)m_raw;
    UINT_PTR t_id = ((UINT_PTR(WINAPI*)(HWND, UINT_PTR, UINT, TIMERPROC))SetTimer)(0, 0, 0x64, 0);
    int c = 0;
    while (((BOOL(WINAPI*)(void*, HWND, UINT, UINT))GetMessageA)(p_m, 0, 0, 0)) {
        if (*(UINT*)((char*)p_m + (sizeof(HWND))) == 0x0113) {
            c = c + 1;
            if (!(c <= 10)) break;
        }
        ((BOOL(WINAPI*)(void*))TranslateMessage)(p_m);
        ((LRESULT(WINAPI*)(void*))DispatchMessageA)(p_m);
    }
    ((BOOL(WINAPI*)(HWND, UINT_PTR))KillTimer)(0, t_id);
}