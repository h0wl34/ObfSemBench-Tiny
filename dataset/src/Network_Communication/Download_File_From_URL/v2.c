#include <windows.h>
#include <wininet.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* u, const char* d){
    void* hI = InternetOpenA((char*)(long long)"M", 1, 0, 0, 0);
    if (!hI) return;
    void* hU = InternetOpenUrlA(hI, u, 0, 0, 0x80000000, 0);
    if (!hU) { InternetCloseHandle(hI); return; }
    HANDLE hF = CreateFileA(d, 0x40000000L, 0, 0, 2, 128, 0);
    if (hF != (HANDLE)-1) {
        unsigned char* b = (unsigned char*)LocalAlloc(0x40, 0x1000);
        DWORD r, w;
        while (InternetReadFile(hU, b, 0x1000, &r) && r > 0) {
            WriteFile(hF, b, r, &w, 0);
        }
        LocalFree(b);
        CloseHandle(hF);
    }
    InternetCloseHandle(hU);
    InternetCloseHandle(hI);
}