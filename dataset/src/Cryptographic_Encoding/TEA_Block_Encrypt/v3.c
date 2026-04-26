#include <windows.h>
#include <stdint.h>

typedef void (WINAPI *pGetSystemTime)(LPSYSTEMTIME);
void __attribute__((noinline)) __attribute__((used)) routine_c_v3(uint32_t* v, uint32_t* k){
    HMODULE h = LoadLibraryA("kernel32.dll");
    pGetSystemTime _time = (pGetSystemTime)GetProcAddress(h, "GetSystemTime");
    SYSTEMTIME st;
    _time(&st);

    uint32_t v0 = v[0], v1 = v[1], sum = 0, delta = 0x9e3779b9;
    for (int i = 0; i < 32; i++) {
        sum += delta;
        v0 += ((v1 << 4) + k[0]) ^ (v1 + sum) ^ ((v1 >> 5) + k[1]);
        v1 += ((v0 << 4) + k[2]) ^ (v0 + sum) ^ ((v0 >> 5) + k[3]);
    }
    v[0] = v0; v[1] = v1;
    FreeLibrary(h);
}