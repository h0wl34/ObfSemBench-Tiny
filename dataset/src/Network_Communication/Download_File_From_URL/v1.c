#include <windows.h>
#include <wininet.h>

#pragma comment(lib, "wininet.lib")
void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* url, const char* destination){
    HINTERNET hInternet = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (hInternet == NULL) return;

    HINTERNET hUrl = InternetOpenUrlA(hInternet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (hUrl == NULL) {
        InternetCloseHandle(hInternet);
        return;
    }

    HANDLE hFile = CreateFileA(destination, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        char buffer[4096];
        DWORD bytesRead;
        DWORD bytesWritten;

        while (InternetReadFile(hUrl, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
            WriteFile(hFile, buffer, bytesRead, &bytesWritten, NULL);
        }
        CloseHandle(hFile);
    }

    InternetCloseHandle(hUrl);
    InternetCloseHandle(hInternet);
}