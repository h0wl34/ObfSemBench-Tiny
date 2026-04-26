#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* f){
    void* s = GetDC(0);
    void* d = CreateCompatibleDC((HDC)s);
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    void* b = CreateCompatibleBitmap((HDC)s, w, h);
    void** pb = &b;
    SelectObject((HDC)d, (HGDIOBJ)*pb);
    BitBlt((HDC)d, 0, 0, w, h, (HDC)s, 0, 0, 0x00CC0020);
    DeleteObject((HGDIOBJ)*pb);
    DeleteDC((HDC)d);
    ReleaseDC(0, (HDC)s);
}