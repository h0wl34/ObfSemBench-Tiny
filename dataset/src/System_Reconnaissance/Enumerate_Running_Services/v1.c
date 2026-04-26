#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(){
    SC_HANDLE hSCM = OpenSCManagerA(NULL, NULL, SC_MANAGER_ENUMERATE_SERVICE);
    if (hSCM) {
        DWORD bytesNeeded, servicesCount, resumeHandle = 0;
        EnumServicesStatusExA(hSCM, SC_ENUM_PROCESS_INFO, SERVICE_WIN32, SERVICE_STATE_ALL, NULL, 0, &bytesNeeded, &servicesCount, &resumeHandle, NULL);
        LPBYTE buffer = (LPBYTE)LocalAlloc(LPTR, bytesNeeded);
        if (EnumServicesStatusExA(hSCM, SC_ENUM_PROCESS_INFO, SERVICE_WIN32, SERVICE_STATE_ALL, buffer, bytesNeeded, &bytesNeeded, &servicesCount, &resumeHandle, NULL)) {
            LPENUM_SERVICE_STATUS_PROCESSA services = (LPENUM_SERVICE_STATUS_PROCESSA)buffer;
            for (DWORD i = 0; i < servicesCount; i++) {
                char* name = services[i].lpServiceName;
            }
        }
        LocalFree(buffer);
        CloseServiceHandle(hSCM);
    }
}