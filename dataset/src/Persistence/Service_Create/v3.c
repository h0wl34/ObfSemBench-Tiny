#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* serviceName, const char* exePath){
    typedef SC_HANDLE (WINAPI *OSMA)(LPCSTR, LPCSTR, DWORD);
    typedef SC_HANDLE (WINAPI *CSA)(SC_HANDLE, LPCSTR, LPCSTR, DWORD, DWORD, DWORD, DWORD, LPCSTR, LPCSTR, LPDWORD, LPCSTR, LPCSTR, LPCSTR);
    typedef BOOL (WINAPI *CSH)(SC_HANDLE);

    HMODULE hAdv = LoadLibraryA("advapi32.dll");
    OSMA pOpen = (OSMA)GetProcAddress(hAdv, "OpenSCManagerA");
    CSA pCreate = (CSA)GetProcAddress(hAdv, "CreateServiceA");
    CSH pClose = (CSH)GetProcAddress(hAdv, "CloseServiceHandle");

    SC_HANDLE scm = pOpen(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
    if (scm) {
        SC_HANDLE svc = pCreate(scm, serviceName, serviceName, SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS, SERVICE_AUTO_START, SERVICE_ERROR_NORMAL, exePath, NULL, NULL, NULL, NULL, NULL);
        if (svc) pClose(svc);
        pClose(scm);
    }
}