#include <windows.h>

unsigned int __attribute__((noinline)) __attribute__((used)) routine_v3(unsigned char* data, int len){
    typedef LPVOID (WINAPI *pVA)(LPVOID, SIZE_T, DWORD, DWORD);
    typedef BOOL (WINAPI *pVF)(LPVOID, SIZE_T, DWORD);

    unsigned int result = 0;
    HMODULE hK32 = GetModuleHandleA("kernel32.dll");
    pVA _VirtualAlloc = (pVA)GetProcAddress(hK32, "VirtualAlloc");
    pVF _VirtualFree = (pVF)GetProcAddress(hK32, "VirtualFree");

    if (_VirtualAlloc && _VirtualFree) {
        unsigned int* table = (unsigned int*)_VirtualAlloc(NULL, 256 * sizeof(unsigned int), MEM_COMMIT, PAGE_READWRITE);
        if (table) {
            for (unsigned int i = 0; i < 256; i++) {
                unsigned int r = i;
                for (int j = 0; j < 8; j++)
                    r = (r >> 1) ^ (0xEDB88320 & (-(int)(r & 1)));
                table[i] = r;
            }
            unsigned int crc = 0xFFFFFFFF;
            for (int i = 0; i < len; i++) {
                crc = (crc >> 8) ^ table[(crc ^ data[i]) & 0xFF];
            }
            result = ~crc;
            _VirtualFree(table, 0, MEM_RELEASE);
        }
    }
    return result;
}