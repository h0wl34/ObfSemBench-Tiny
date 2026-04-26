#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* filename){
    typedef HDC (WINAPI *GDC)(HWND);
    typedef HDC (WINAPI *CDC)(HDC);
    typedef HBITMAP (WINAPI *CCB)(HDC, int, int);
    typedef BOOL (WINAPI *BB)(HDC, int, int, int, int, HDC, int, int, DWORD);

    HMODULE hU = GetModuleHandleA("user32.dll");
    HMODULE hG = GetModuleHandleA("gdi32.dll");

    GDC pGetDC = (GDC)GetProcAddress(hU, "GetDC");
    CDC pCreateDC = (CDC)GetProcAddress(hG, "CreateCompatibleDC");
    CCB pCreateBmp = (CCB)GetProcAddress(hG, "CreateCompatibleBitmap");
    BB pBitBlt = (BB)GetProcAddress(hG, "BitBlt");

    HDC hScr = pGetDC(NULL);
    HDC hMem = pCreateDC(hScr);
    HBITMAP hBmp = pCreateBmp(hScr, 800, 600);
    SelectObject(hMem, hBmp);
    pBitBlt(hMem, 0, 0, 800, 600, hScr, 0, 0, SRCCOPY);
    
    DeleteObject(hBmp);
    DeleteDC(hMem);
    ReleaseDC(NULL, hScr);
}