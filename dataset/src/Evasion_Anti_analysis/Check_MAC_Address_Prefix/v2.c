#include <windows.h>
#include <iphlpapi.h>

int __attribute__((noinline)) __attribute__((used)) routine_v2(){
    unsigned char b[1024];
    unsigned long l = 1024;
    if (GetAdaptersInfo((PIP_ADAPTER_INFO)b, &l) == 0) {
        unsigned char* p = b;
        if (*(p + 400) == 0x08 && *(p + 401) == 0x00 && *(p + 402) == 0x27) return 1;
    }
    return 0;
}