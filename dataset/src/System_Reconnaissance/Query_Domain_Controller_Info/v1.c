#include <windows.h>
#include <dsgetdc.h>
#include <lm.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(){
    PDOMAIN_CONTROLLER_INFOA pdci = NULL;
    if (DsGetDcNameA(NULL, NULL, NULL, NULL, 0, &pdci) == ERROR_SUCCESS) {
        char* dcName = pdci->DomainControllerName;
        NetApiBufferFree(pdci);
    }
}