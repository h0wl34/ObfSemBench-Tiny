#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* filename){
    HDC hScreen = GetDC(NULL);
    HDC hDC = CreateCompatibleDC(hScreen);
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, x, y);
    SelectObject(hDC, hBitmap);
    BitBlt(hDC, 0, 0, x, y, hScreen, 0, 0, SRCCOPY);
    DeleteObject(hBitmap);
    DeleteDC(hDC);
    ReleaseDC(NULL, hScreen);
}