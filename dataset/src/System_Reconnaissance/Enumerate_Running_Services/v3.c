#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(){
    HMODULE hAdv = LoadLibraryA("advapi32.dll");
    typedef SC_HANDLE(WINAPI* fOSM)(LPCSTR, LPCSTR, DWORD);
    typedef BOOL(WINAPI* fESS)(SC_HANDLE, SC_ENUM_TYPE, DWORD, DWORD, LPBYTE, DWORD, LPDWORD, LPDWORD, LPDWORD, LPCSTR);
    fOSM _OSM = (fOSM)GetProcAddress(hAdv, "OpenSCManagerA");
    fESS _ESS = (fESS)GetProcAddress(hAdv, "EnumServicesStatusExA");
    SC_HANDLE h = _OSM(NULL, NULL, SC_MANAGER_ENUMERATE_SERVICE);
    if (h) {
        DWORD bN, sC, rH = 0;
        _ESS(h, SC_ENUM_PROCESS_INFO, SERVICE_WIN32, SERVICE_STATE_ALL, NULL, 0, &bN, &sC, &rH, NULL);
        LPBYTE buf = (LPBYTE)LocalAlloc(LPTR, bN);
        _ESS(h, SC_ENUM_PROCESS_INFO, SERVICE_WIN32, SERVICE_STATE_ALL, buf, bN, &bN, &sC, &rH, NULL);
        LocalFree(buf);
        CloseServiceHandle(h);
    }
}