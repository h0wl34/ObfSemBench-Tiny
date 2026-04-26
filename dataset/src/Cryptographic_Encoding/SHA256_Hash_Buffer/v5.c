#include <windows.h>
#include <wincrypt.h>

void __attribute__((noinline)) __attribute__((used)) routine_a_v5(BYTE* buffer, DWORD len, BYTE* out){
    int state = 10;
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    DWORD hLen = 32;

    while (state != 0) {
        switch (state) {
            case 10:
                if (CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) state = 20;
                else state = 0;
                break;
            case 20:
                if (CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) state = 30;
                else state = 40;
                break;
            case 30:
                CryptHashData(hHash, buffer, len, 0);
                CryptGetHashParam(hHash, HP_HASHVAL, out, &hLen, 0);
                CryptDestroyHash(hHash);
                state = 40;
                break;
            case 40:
                CryptReleaseContext(hProv, 0);
                state = 0;
                break;
        }
    }
}