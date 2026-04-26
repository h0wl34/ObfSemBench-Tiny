#include <windows.h>

typedef BOOL (WINAPI *pCryptAcquireContextA)(HCRYPTPROV*, LPCSTR, LPCSTR, DWORD, DWORD);
typedef BOOL (WINAPI *pCryptCreateHash)(HCRYPTPROV, ALG_ID, HCRYPTKEY, DWORD, HCRYPTHASH*);
typedef BOOL (WINAPI *pCryptHashData)(HCRYPTHASH, const BYTE*, DWORD, DWORD);
typedef BOOL (WINAPI *pCryptGetHashParam)(HCRYPTHASH, DWORD, BYTE*, DWORD*, DWORD);
typedef BOOL (WINAPI *pCryptDestroyHash)(HCRYPTHASH);
typedef BOOL (WINAPI *pCryptReleaseContext)(HCRYPTPROV, DWORD);
void __attribute__((noinline)) __attribute__((used)) routine_a_v3(BYTE* input, DWORD input_len, BYTE* output){
    HMODULE hAdv = LoadLibraryA("advapi32.dll");
    if (!hAdv) return;

    pCryptAcquireContextA _Acquire = (pCryptAcquireContextA)GetProcAddress(hAdv, "CryptAcquireContextA");
    pCryptCreateHash _Create = (pCryptCreateHash)GetProcAddress(hAdv, "CryptCreateHash");
    pCryptHashData _Hash = (pCryptHashData)GetProcAddress(hAdv, "CryptHashData");
    pCryptGetHashParam _GetParam = (pCryptGetHashParam)GetProcAddress(hAdv, "CryptGetHashParam");
    pCryptDestroyHash _Destroy = (pCryptDestroyHash)GetProcAddress(hAdv, "CryptDestroyHash");
    pCryptReleaseContext _Release = (pCryptReleaseContext)GetProcAddress(hAdv, "CryptReleaseContext");

    HCRYPTPROV hProv;
    HCRYPTHASH hHash;
    DWORD outLen = 32;

    if (_Acquire(&hProv, NULL, NULL, 24, 0xF0000000)) {
        if (_Create(hProv, 0x0000800c, 0, 0, &hHash)) {
            _Hash(hHash, input, input_len, 0);
            _GetParam(hHash, 2, output, &outLen, 0);
            _Destroy(hHash);
        }
        _Release(hProv, 0);
    }
    FreeLibrary(hAdv);
}