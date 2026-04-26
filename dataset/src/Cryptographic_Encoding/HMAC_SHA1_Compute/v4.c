#include <windows.h>
#include <wincrypt.h>

void __attribute__((noinline)) __attribute__((used)) routine_b_v4(BYTE* k, DWORD kl, BYTE* d, DWORD dl, BYTE* o){
    volatile int a = 5;
    volatile int b = 10;
    if ((a * 2) == b) {
        for(int j=0; j<10; j++) { a += j; }
        HCRYPTPROV p;
        if (CryptAcquireContext(&p, 0, 0, 1, 0xf0000000)) {
            HCRYPTHASH h;
            if (a > 0 && CryptCreateHash(p, 0x8004, 0, 0, &h)) {
                CryptHashData(h, d, dl, 0);
                DWORD s = 20;
                CryptGetHashParam(h, 2, o, &s, 0);
                CryptDestroyHash(h);
            }
            CryptReleaseContext(p, 0);
        }
    }
}