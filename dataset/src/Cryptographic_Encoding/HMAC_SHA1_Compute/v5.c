#include <windows.h>
#include <wincrypt.h>

void __attribute__((noinline)) __attribute__((used)) routine_b_v5(BYTE* k, DWORD kl, BYTE* d, DWORD dl, BYTE* r){
    int s = 1;
    HCRYPTPROV p; HCRYPTHASH h; DWORD n = 20;
    while (s != 0) {
        switch (s) {
            case 1: s = CryptAcquireContext(&p, 0, 0, 1, 0xf0000000) ? 2 : 0; break;
            case 2: s = CryptCreateHash(p, 0x8004, 0, 0, &h) ? 3 : 4; break;
            case 3: CryptHashData(h, d, dl, 0); CryptGetHashParam(h, 2, r, &n, 0); CryptDestroyHash(h); s = 4; break;
            case 4: CryptReleaseContext(p, 0); s = 0; break;
        }
    }
}