#include <windows.h>
#include <iphlpapi.h>

int __attribute__((noinline)) __attribute__((used)) routine_v1(){
    IP_ADAPTER_INFO AdapterInfo[16];
    DWORD dwBufLen = sizeof(AdapterInfo);
    if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == ERROR_SUCCESS) {
        PIP_ADAPTER_INFO pAdapter = AdapterInfo;
        if (pAdapter->Address[0] == 0x08 && pAdapter->Address[1] == 0x00 && pAdapter->Address[2] == 0x27) return 1;
    }
    return 0;
}