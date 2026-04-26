#include <windows.h>

void* __attribute__((noinline)) __attribute__((used)) routine_v5(void* m, unsigned int h){
    int s = 0, i = 0;
    unsigned char* b = (unsigned char*)m;
    unsigned char* exp = 0;
    int* ns = 0;
    int cnt = 0;
    void* res = 0;
    while (s != -1) {
        switch (s) {
        case 0:
            exp = b + *(int*)(b + *(int*)(b + 0x3C) + 0x78);
            s = 1;
            break;
        case 1:
            ns = (int*)(b + *(int*)(exp + 0x20));
            cnt = *(int*)(exp + 0x18);
            i = 0;
            s = 2;
            break;
        case 2:
            if (i >= cnt) s = -1;
            else {
                char* n = (char*)(b + ns[i]);
                unsigned int ch = 0;
                while (*n) ch = (ch << 5) + *n++;
                if (ch == h) s = 3;
                else i++, s = 2;
            }
            break;
        case 3:
            res = (void*)(b + ((int*)(b + *(int*)(exp + 0x1C)))[((unsigned short*)(b + *(int*)(exp + 0x24)))[i]]);
            s = -1;
            break;
        }
    }
    return res;
}