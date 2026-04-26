#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(void* b){
    char* nt = (char*)b + *(int*)((char*)b + 0x3C);
    unsigned int r_va = *(unsigned int*)(nt + 0xA0);
    if (r_va != 0) {
        char* r = (char*)b + r_va;
        while (*(unsigned int*)r != 0) {
            unsigned int sz = *(unsigned int*)(r + 4);
            r += sz;
        }
    }
}