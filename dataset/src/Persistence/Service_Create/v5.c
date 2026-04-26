#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* serviceName, const char* exePath){
    SC_HANDLE scm = NULL;
    SC_HANDLE svc = NULL;
    int step = 1;
    while (step != 0) {
        switch (step) {
            case 1:
                scm = OpenSCManagerA(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
                step = scm ? 2 : 0;
                break;
            case 2:
                svc = CreateServiceA(scm, serviceName, serviceName, SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS, SERVICE_AUTO_START, SERVICE_ERROR_NORMAL, exePath, NULL, NULL, NULL, NULL, NULL);
                step = 3;
                break;
            case 3:
                if (svc) CloseServiceHandle(svc);
                if (scm) CloseServiceHandle(scm);
                step = 0;
                break;
        }
    }
}