#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_b_v2(unsigned char* k, int kl, unsigned char* d, int dl, unsigned char* out){
    unsigned char ipad[64], opad[64];
    unsigned char tk[20];
    int i;

    for (i = 0; i < 64; i++) {
        *(ipad + i) = 0x36 ^ (i < kl ? *(k + i) : 0);
        *(opad + i) = 0x5c ^ (i < kl ? *(k + i) : 0);
    }

    HCRYPTPROV p;
    HCRYPTHASH h;
    DWORD rl = 20;
    CryptAcquireContext(&p, 0, 0, 1, 0xf0000000);
    
    CryptCreateHash(p, 0x8004, 0, 0, &h);
    CryptHashData(h, ipad, 64, 0);
    CryptHashData(h, d, dl, 0);
    CryptGetHashParam(h, 2, tk, &rl, 0);
    CryptDestroyHash(h);

    CryptCreateHash(p, 0x8004, 0, 0, &h);
    CryptHashData(h, opad, 64, 0);
    CryptHashData(h, tk, 20, 0);
    CryptGetHashParam(h, 2, out, &rl, 0);
    CryptDestroyHash(h);
    CryptReleaseContext(p, 0);
}