#include <windows.h>

BOOL __attribute__((noinline)) __attribute__((used)) routine_v3(){
    HMODULE h = GetModuleHandleA("advapi32.dll");
    typedef BOOL(WINAPI* fCTM)(HANDLE, PSID, PBOOL);
    typedef BOOL(WINAPI* fAAIS)(PSID_IDENTIFIER_AUTHORITY, BYTE, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, PSID*);
    fCTM _CTM = (fCTM)GetProcAddress(h, "CheckTokenMembership");
    fAAIS _AAIS = (fAAIS)GetProcAddress(h, "AllocateAndInitializeSid");
    SID_IDENTIFIER_AUTHORITY auth = SECURITY_NT_AUTHORITY;
    PSID adm;
    BOOL res = FALSE;
    if (_AAIS(&auth, 2, 32, 544, 0, 0, 0, 0, 0, 0, &adm)) {
        _CTM(NULL, adm, &res);
        FreeSid(adm);
    }
    return res;
}