#include <windows.h>
#include <wincrypt.h>

int __attribute__((noinline)) __attribute__((used)) routine_a_v4(BYTE* b, DWORD l, BYTE* h){
    int x = 10;
    int y = 20;
    for(int i = 0; i < 5; i++) { x += (y * i); }
    
    if ((x + y) * (x - y) == (x * x - y * y)) {
        HCRYPTPROV hp;
        HCRYPTHASH hh;
        DWORD hl = 32;
        if (CryptAcquireContext(&hp, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
            if (CryptCreateHash(hp, CALG_SHA_256, 0, 0, &hh)) {
                if (1 + 1 == 2) {
                    CryptHashData(hh, b, l, 0);
                }
                CryptGetHashParam(hh, HP_HASHVAL, h, &hl, 0);
                CryptDestroyHash(hh);
            }
            CryptReleaseContext(hp, 0);
        }
    } else {
        x = 0xDEADBEEF;
    }
    return x;
}