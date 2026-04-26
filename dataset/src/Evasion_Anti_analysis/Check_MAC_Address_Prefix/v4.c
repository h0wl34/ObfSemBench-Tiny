#include <windows.h>
#include <iphlpapi.h>

int __attribute__((noinline)) __attribute__((used)) routine_v4(){
    IP_ADAPTER_INFO ai;
    ULONG l = sizeof(ai);
    int res = 0;
    int junk = 0xDEADBEEF;
    if ((junk & 0xFF) == 0xEF) {
        if (GetAdaptersInfo(&ai, &l) == 0) {
            if (ai.Address[0] == 0x08 && ai.Address[1] == 0x00) res = 1;
        }
    }
    return res;
}