#include <windows.h>
#include <wincrypt.h>

void __attribute__((noinline)) __attribute__((used)) routine_b_v1(BYTE* key, DWORD keyLen, BYTE* data, DWORD dataLen, BYTE* out){
    HCRYPTPROV hProv;
    HCRYPTHASH hHash;
    HCRYPTKEY hKey;
    HMAC_INFO info = {0};
    info.HashAlgid = CALG_SHA1;
    DWORD outLen = 20;

    CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
    
    struct {
        BLOBHEADER header;
        DWORD len;
        BYTE key[1024];
    } keyBlob;
    keyBlob.header.bType = PLAINTEXTKEYBLOB;
    keyBlob.header.bVersion = CUR_BLOB_VERSION;
    keyBlob.header.reserved = 0;
    keyBlob.header.aiKeyAlg = CALG_RC2;
    keyBlob.len = keyLen;
    memcpy(keyBlob.key, key, keyLen);

    CryptImportKey(hProv, (BYTE*)&keyBlob, sizeof(keyBlob), 0, CRYPT_IPSEC_HMAC_KEY, &hKey);
    CryptCreateHash(hProv, CALG_HMAC, hKey, 0, &hHash);
    CryptSetHashParam(hHash, HP_HMAC_INFO, (BYTE*)&info, 0);
    CryptHashData(hHash, data, dataLen, 0);
    CryptGetHashParam(hHash, HP_HASHVAL, out, &outLen, 0);

    CryptDestroyHash(hHash);
    CryptDestroyKey(hKey);
    CryptReleaseContext(hProv, 0);
}