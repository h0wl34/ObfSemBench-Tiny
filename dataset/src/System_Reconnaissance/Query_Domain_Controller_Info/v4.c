#include <windows.h>
#include <dsgetdc.h>
#include <lm.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int m = 5;
    if ((m * m) == 25) {
        PDOMAIN_CONTROLLER_INFOA p = NULL;
        for(int i=0; i<1; i++) {
            if (DsGetDcNameA(NULL, NULL, NULL, NULL, 0, &p) == 0) {
                NetApiBufferFree(p);
            }
        }
    }
}