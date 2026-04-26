#include <windows.h>

void* __attribute__((noinline)) __attribute__((used)) routine_v4(void* m, unsigned int h){
    unsigned char* b = (unsigned char*)m;
    if (1 + 1 == 2) {
        int e = *(int*)(b + 0x3C);
        unsigned char* exp = b + *(int*)(b + e + 0x78);
        int* ns = (int*)(b + *(int*)(exp + 0x20));
        for (int i = 0; i < *(int*)(exp + 0x18); i++) {
            char* n = (char*)(b + ns[i]);
            unsigned int ch = 0;
            for(int k=0; n[k]; k++) { ch = (ch ^ n[k]) * 16777619; }
            if (ch == h) {
                unsigned short o = ((unsigned short*)(b + *(int*)(exp + 0x24)))[i];
                return (void*)(b + ((int*)(b + *(int*)(exp + 0x1C)))[o]);
            }
        }
    }
    return 0;
}