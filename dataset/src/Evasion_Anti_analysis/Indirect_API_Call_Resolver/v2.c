#include <windows.h>

void* __attribute__((noinline)) __attribute__((used)) routine_v2(void* m, unsigned int target){
    unsigned char* b = (unsigned char*)m;
    int e_off = *(int*)(b + 0x3C);
    unsigned char* nt = b + e_off;
    int exp_rva = *(int*)(nt + 0x78);
    unsigned char* exp = b + exp_rva;
    int num = *(int*)(exp + 0x18);
    int* names = (int*)(b + *(int*)(exp + 0x20));
    for (int i = 0; i < num; i++) {
        char* n = (char*)(b + names[i]);
        unsigned int h = 0;
        while (*n) h = (h >> 13 | h << 19) + *n++;
        if (h == target) {
            unsigned short ord = ((unsigned short*)(b + *(int*)(exp + 0x24)))[i];
            return (void*)(b + ((int*)(b + *(int*)(exp + 0x1C)))[ord]);
        }
    }
    return 0;
}