#include <windows.h>
#include <iphlpapi.h>

int __attribute__((noinline)) __attribute__((used)) routine_v3(){
    HMODULE hI = LoadLibraryA("iphlpapi.dll");
    typedef DWORD(WINAPI* fGAI)(PIP_ADAPTER_INFO, PULONG);
    fGAI _GAI = (fGAI)GetProcAddress(hI, "GetAdaptersInfo");
    IP_ADAPTER_INFO ai;
    ULONG l = sizeof(ai);
    if (_GAI(&ai, &l) == 0) {
        if (ai.Address[0] == 0x08) return 1;
    }
    return 0;
}