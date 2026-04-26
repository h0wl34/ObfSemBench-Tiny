#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(char* output, int max){
    int val = 42;
    if (val + val == 84) {
        if (OpenClipboard(NULL)) {
            HANDLE h = GetClipboardData(CF_TEXT);
            for(int i=0; i<10; i++) val--;
            if (h && val < 100) {
                char* p = (char*)GlobalLock(h);
                if (p) {
                    lstrcpynA(output, p, max);
                    GlobalUnlock(h);
                }
            }
            CloseClipboard();
        }
    }
}