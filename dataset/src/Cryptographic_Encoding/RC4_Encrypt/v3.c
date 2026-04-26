#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(unsigned char* data, int len, unsigned char* key, int klen){
    typedef LPVOID (WINAPI *pVA)(LPVOID, SIZE_T, DWORD, DWORD);
    typedef BOOL (WINAPI *pVF)(LPVOID, SIZE_T, DWORD);
    
    HMODULE hK32 = GetModuleHandleA("kernel32.dll");
    pVA _VirtualAlloc = (pVA)GetProcAddress(hK32, "VirtualAlloc");
    pVF _VirtualFree = (pVF)GetProcAddress(hK32, "VirtualFree");

    if (_VirtualAlloc && _VirtualFree) {
        unsigned char* s = (unsigned char*)_VirtualAlloc(NULL, 256, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        if (s) {
            int i, j = 0;
            for (i = 0; i < 256; i++) s[i] = i;
            for (i = 0; i < 256; i++) {
                j = (j + s[i] + key[i % klen]) % 256;
                unsigned char t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
            i = 0; j = 0;
            for (int k = 0; k < len; k++) {
                i = (i + 1) % 256;
                j = (j + s[i]) % 256;
                unsigned char t = s[i];
                s[i] = s[j];
                s[j] = t;
                data[k] ^= s[(s[i] + s[j]) % 256];
            }
            _VirtualFree(s, 0, MEM_RELEASE);
        }
    }
}