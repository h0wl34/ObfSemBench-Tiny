#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_b_v3(BYTE* k, DWORD kl, BYTE* d, DWORD dl, BYTE* r){
    HMODULE a = LoadLibraryA("advapi32.dll");
    BOOL (WINAPI *acq)(HCRYPTPROV*, LPCSTR, LPCSTR, DWORD, DWORD) = (void*)GetProcAddress(a, "CryptAcquireContextA");
    BOOL (WINAPI *crh)(HCRYPTPROV, ALG_ID, HCRYPTKEY, DWORD, HCRYPTHASH*) = (void*)GetProcAddress(a, "CryptCreateHash");
    BOOL (WINAPI *hda)(HCRYPTHASH, const BYTE*, DWORD, DWORD) = (void*)GetProcAddress(a, "CryptHashData");
    BOOL (WINAPI *gpa)(HCRYPTHASH, DWORD, BYTE*, DWORD*, DWORD) = (void*)GetProcAddress(a, "CryptGetHashParam");
    BOOL (WINAPI *dsh)(HCRYPTHASH) = (void*)GetProcAddress(a, "CryptDestroyHash");
    BOOL (WINAPI *rls)(HCRYPTPROV, DWORD) = (void*)GetProcAddress(a, "CryptReleaseContext");

    HCRYPTPROV p; HCRYPTHASH h; DWORD s = 20;
    if (acq(&p, 0, 0, 1, 0xf0000000)) {
        if (crh(p, 0x8004, 0, 0, &h)) {
            hda(h, d, dl, 0);
            gpa(h, 2, r, &s, 0);
            dsh(h);
        }
        rls(p, 0);
    }
}