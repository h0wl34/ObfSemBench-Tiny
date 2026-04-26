#include <windows.h>
#include <iphlpapi.h>

int __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int state = 10;
    IP_ADAPTER_INFO ai;
    ULONG l = sizeof(ai);
    int detected = 0;
    while (state != 0) {
        switch (state) {
        case 10:
            if (GetAdaptersInfo(&ai, &l) == 0) state = 20;
            else state = 0;
            break;
        case 20:
            if (ai.Address[0] == 0x08) detected = 1;
            state = 0;
            break;
        }
    }
    return detected;
}