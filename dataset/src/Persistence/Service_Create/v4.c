#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* serviceName, const char* exePath){
    int v = 100;
    if (v / 10 == 10) {
        SC_HANDLE scm = OpenSCManagerA(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
        if (scm) {
            if (v > 50) {
                SC_HANDLE svc = CreateServiceA(scm, serviceName, serviceName, SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS, SERVICE_AUTO_START, SERVICE_ERROR_NORMAL, exePath, NULL, NULL, NULL, NULL, NULL);
                if (svc) CloseServiceHandle(svc);
            }
            CloseServiceHandle(scm);
        }
    }
}