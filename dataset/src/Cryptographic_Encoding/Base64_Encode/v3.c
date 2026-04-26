#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(unsigned char* in, int in_len, char* out){
    typedef HANDLE (WINAPI *pGPH)();
    typedef LPVOID (WINAPI *pHA)(HANDLE, DWORD, SIZE_T);
    typedef BOOL (WINAPI *pHF)(HANDLE, DWORD, LPVOID);

    HMODULE h = GetModuleHandleA("kernel32.dll");
    pGPH _g = (pGPH)GetProcAddress(h, "GetProcessHeap");
    pHA _a = (pHA)GetProcAddress(h, "HeapAlloc");
    pHF _f = (pHF)GetProcAddress(h, "HeapFree");

    if (_g && _a && _f) {
        char* b = (char*)_a(_g(), 0, 65);
        for(int i=0; i<26; i++) { b[i] = 'A'+i; b[i+26] = 'a'+i; }
        for(int i=0; i<10; i++) b[i+52] = '0'+i;
        b[62] = '+'; b[63] = '/'; b[64] = 0;

        int i = 0, j = 0;
        while (i < in_len) {
            unsigned int n = in[i] << 16;
            if (i + 1 < in_len) n |= in[i+1] << 8;
            if (i + 2 < in_len) n |= in[i+2];
            
            out[j++] = b[(n >> 18) & 63];
            out[j++] = b[(n >> 12) & 63];
            out[j++] = (i + 1 < in_len) ? b[(n >> 6) & 63] : '=';
            out[j++] = (i + 2 < in_len) ? b[n & 63] : '=';
            i += 3;
        }
        out[j] = 0;
        _f(_g(), 0, b);
    }
}