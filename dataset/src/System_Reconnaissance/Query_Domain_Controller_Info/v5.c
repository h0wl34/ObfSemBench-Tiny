#include <windows.h>
#include <dsgetdc.h>
#include <lm.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int s = 10;
    PDOMAIN_CONTROLLER_INFOA p = NULL;
    while (s != 0) {
        switch (s) {
        case 10:
            if (DsGetDcNameA(NULL, NULL, NULL, NULL, 0, &p) == 0) s = 20;
            else s = 0;
            break;
        case 20:
            NetApiBufferFree(p);
            s = 0;
            break;
        }
    }
}