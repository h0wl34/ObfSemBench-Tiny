#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(){
    HMODULE hNet = LoadLibraryA("netapi32.dll");
    typedef DWORD(WINAPI* fDGN)(LPCSTR, LPCSTR, GUID*, LPCSTR, ULONG, PVOID);
    fDGN _DGN = (fDGN)GetProcAddress(hNet, "DsGetDcNameA");
    PVOID p = NULL;
    if (_DGN && _DGN(NULL, NULL, NULL, NULL, 0, &p) == 0) {
        FARPROC _NBF = GetProcAddress(hNet, "NetApiBufferFree");
        ((DWORD(WINAPI*)(PVOID))_NBF)(p);
    }
}