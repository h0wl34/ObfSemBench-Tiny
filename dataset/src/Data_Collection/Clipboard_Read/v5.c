#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(char* output, int max){
    HANDLE h = NULL;
    int state = 1;
    while (state != 0) {
        switch (state) {
            case 1:
                state = OpenClipboard(NULL) ? 2 : 0;
                break;
            case 2:
                h = GetClipboardData(CF_TEXT);
                state = h ? 3 : 4;
                break;
            case 3:
                {
                    char* p = (char*)GlobalLock(h);
                    if (p) {
                        lstrcpynA(output, p, max);
                        GlobalUnlock(h);
                    }
                }
                state = 4;
                break;
            case 4:
                CloseClipboard();
                state = 0;
                break;
        }
    }
}