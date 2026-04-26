#include <windows.h>
#include <stdint.h>

void __attribute__((noinline)) __attribute__((used)) routine_c_v2(void* data, void* key){
    unsigned int* d = (unsigned int*)data;
    unsigned int* k = (unsigned int*)key;
    unsigned int s = 0;
    int i = 32;
    while (i--) {
        s += 0x9E3779B9;
        *(d) += (((*(d + 1) << 4) + *(k)) ^ (*(d + 1) + s) ^ ((*(d + 1) >> 5) + *(k + 1)));
        *(d + 1) += (((*(d) << 4) + *(k + 2)) ^ (*(d) + s) ^ ((*(d) >> 5) + *(k + 3)));
    }
}