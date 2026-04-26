#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_a_v2(const unsigned char* msg, size_t len, unsigned int* hash){
    unsigned int a, b, c, d, e, f, g, h, t1, t2;
    unsigned int w[64];
    unsigned int k[] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174
    };

    hash[0] = 0x6a09e667; hash[1] = 0xbb67ae85; hash[2] = 0x3c6ef372; hash[3] = 0xa54ff53a;
    hash[4] = 0x510e527f; hash[5] = 0x9b05688c; hash[6] = 0x1f83d9ab; hash[7] = 0x5be0cd19;

    for (size_t i = 0; i < len / 64; ++i) {
        const unsigned char* p = msg + (i * 64);
        for (int j = 0; j < 16; ++j) {
            w[j] = (p[j * 4] << 24) | (p[j * 4 + 1] << 16) | (p[j * 4 + 2] << 8) | (p[j * 4 + 3]);
        }
        
        a = *(hash); b = *(hash + 1); c = *(hash + 2); d = *(hash + 3);
        e = *(hash + 4); f = *(hash + 5); g = *(hash + 6); h = *(hash + 7);

        for (int j = 0; j < 16; ++j) {
            t1 = h + (((e >> 6) | (e << 26)) ^ ((e >> 11) | (e << 21)) ^ ((e >> 25) | (e << 7))) + ((e & f) ^ (~e & g)) + k[j] + w[j];
            t2 = (((a >> 2) | (a << 30)) ^ ((a >> 13) | (a << 19)) ^ ((a >> 22) | (a << 10))) + ((a & b) ^ (a & c) ^ (b & c));
            h = g; g = f; f = e; e = d + t1; d = c; c = b; b = a; a = t1 + t2;
        }
        
        *(hash) += a; *(hash + 1) += b; *(hash + 2) += c; *(hash + 3) += d;
        *(hash + 4) += e; *(hash + 5) += f; *(hash + 6) += g; *(hash + 7) += h;
    }
}