#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(char* output, int max){
    if (OpenClipboard(NULL)) {
        HANDLE hData = GetClipboardData(CF_TEXT);
        if (hData) {
            char* pText = (char*)GlobalLock(hData);
            if (pText) {
                lstrcpynA(output, pText, max);
                GlobalUnlock(hData);
            }
        }
        CloseClipboard();
    }
}