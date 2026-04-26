#include <windows.h>
#include <stdint.h>

void __attribute__((noinline)) __attribute__((used)) routine_c_v5(uint32_t* v, uint32_t* k){
    uint32_t v0 = v[0], v1 = v[1], sum = 0;
    int i = 0, state = 1;
    while (state != 0) {
        switch (state) {
            case 1: if (i < 32) state = 2; else state = 3; break;
            case 2:
                sum += 0x9e3779b9;
                v0 += ((v1 << 4) + k[0]) ^ (v1 + sum) ^ ((v1 >> 5) + k[1]);
                v1 += ((v0 << 4) + k[2]) ^ (v0 + sum) ^ ((v0 >> 5) + k[3]);
                i++; state = 1; break;
            case 3: v[0] = v0; v[1] = v1; state = 0; break;
        }
    }
}