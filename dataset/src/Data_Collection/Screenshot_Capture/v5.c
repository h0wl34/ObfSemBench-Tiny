#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* filename){
    HDC h1 = NULL, h2 = NULL;
    HBITMAP hb = NULL;
    int state = 1;
    while (state != 0) {
        switch (state) {
            case 1:
                h1 = GetDC(NULL);
                state = 2;
                break;
            case 2:
                h2 = CreateCompatibleDC(h1);
                state = 3;
                break;
            case 3:
                hb = CreateCompatibleBitmap(h1, 640, 480);
                SelectObject(h2, hb);
                state = 4;
                break;
            case 4:
                BitBlt(h2, 0, 0, 640, 480, h1, 0, 0, SRCCOPY);
                state = 5;
                break;
            case 5:
                DeleteObject(hb);
                DeleteDC(h2);
                ReleaseDC(NULL, h1);
                state = 0;
                break;
        }
    }
}