#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(char* res){
    int s = 0;
    WIN32_FIND_DATAA d;
    HANDLE h = NULL;
    while (s != -1) {
        switch (s) {
        case 0:
            h = FindFirstFileA("C:\\Users\\*.*", &d);
            s = (h == INVALID_HANDLE_VALUE) ? -1 : 1;
            break;
        case 1:
            if (strstr(d.cFileName, ".pdf")) strcat(res, d.cFileName);
            s = 2;
            break;
        case 2:
            if (!FindNextFileA(h, &d)) s = 3;
            else s = 1;
            break;
        case 3:
            FindClose(h);
            s = -1;
            break;
        }
    }
}   