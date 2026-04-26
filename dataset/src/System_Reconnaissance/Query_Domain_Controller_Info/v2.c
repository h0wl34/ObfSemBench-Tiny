#include <windows.h>
#include <dsgetdc.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(){
    void* p = 0;
    typedef DWORD(WINAPI* fG)(LPCSTR, LPCSTR, GUID*, LPCSTR, ULONG, PDOMAIN_CONTROLLER_INFOA*);
    fG g = (fG)GetProcAddress(LoadLibraryA("netapi32.dll"), "DsGetDcNameA");
    if (g(0, 0, 0, 0, 0, (PDOMAIN_CONTROLLER_INFOA*)&p) == 0) {
        char* n = *(char**)p;
        typedef DWORD(WINAPI* fF)(LPVOID);
        fF f = (fF)GetProcAddress(GetModuleHandleA("netapi32.dll"), "NetApiBufferFree");
        f(p);
    }
}