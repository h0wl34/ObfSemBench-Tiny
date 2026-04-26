#include <windows.h>
#include <stdint.h>

void __attribute__((noinline)) __attribute__((used)) routine_c_v4(uint32_t* v, uint32_t* k){
    int m = 100;
    if (m * m >= 0) {
        uint32_t v0 = v[0], v1 = v[1], s = 0;
        for (int i = 0; i < 32; i++) {
            if (i < 100) {
                s += 0x9e3779b9;
                v0 += ((v1 << 4) + k[0]) ^ (v1 + s) ^ ((v1 >> 5) + k[1]);
                v1 += ((v0 << 4) + k[2]) ^ (v0 + s) ^ ((v0 >> 5) + k[3]);
            }
            m++;
        }
        v[0] = v0; v[1] = v1;
    }
}