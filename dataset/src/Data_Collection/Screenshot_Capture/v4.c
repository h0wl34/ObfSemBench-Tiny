#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* filename){
    int check = 0xABC;
    if ((check ^ 0xABC) == 0) {
        HDC h1 = GetDC(NULL);
        for(int i=0; i<10; i++) check += i;
        HDC h2 = CreateCompatibleDC(h1);
        if (check > 0) {
            HBITMAP hB = CreateCompatibleBitmap(h1, 100, 100);
            SelectObject(h2, hB);
            BitBlt(h2, 0, 0, 100, 100, h1, 0, 0, SRCCOPY);
            DeleteObject(hB);
        }
        DeleteDC(h2);
        ReleaseDC(NULL, h1);
    }
}