#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(char* o, int m){
    if (OpenClipboard(0)) {
        void* h = GetClipboardData(1);
        if (h) {
            char* p = (char*)GlobalLock(h);
            if (p) {
                char* d = o;
                int c = 0;
                while (*p && c < m - 1) {
                    *d++ = *p++;
                    c++;
                }
                *d = 0;
                GlobalUnlock(h);
            }
        }
        CloseClipboard();
    }
}