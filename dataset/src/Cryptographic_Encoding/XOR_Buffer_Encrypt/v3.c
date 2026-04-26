#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(unsigned char* data, int len, unsigned char* key, int klen){
    typedef HANDLE (WINAPI *pGPH)();
    typedef LPVOID (WINAPI *pHA)(HANDLE, DWORD, SIZE_T);
    typedef BOOL (WINAPI *pHF)(HANDLE, DWORD, LPVOID);

    HMODULE hK32 = LoadLibraryA("kernel32.dll");
    if (hK32) {
        pGPH _GetProcessHeap = (pGPH)GetProcAddress(hK32, "GetProcessHeap");
        pHA _HeapAlloc = (pHA)GetProcAddress(hK32, "HeapAlloc");
        pHF _HeapFree = (pHF)GetProcAddress(hK32, "HeapFree");

        if (_GetProcessHeap && _HeapAlloc && _HeapFree) {
            HANDLE hHeap = _GetProcessHeap();
            unsigned char* k_copy = (unsigned char*)_HeapAlloc(hHeap, 0, klen);
            if (k_copy) {
                for (int j = 0; j < klen; j++) k_copy[j] = key[j];
                for (int i = 0; i < len; i++) {
                    data[i] ^= k_copy[i % klen];
                }
                _HeapFree(hHeap, 0, k_copy);
            }
        }
    }
}