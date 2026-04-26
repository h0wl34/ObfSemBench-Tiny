#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_h_v2(char* r, char* b){
    char* p = r;
    int found = 0;
    while (*p) {
        if (*(unsigned int*)p == 0x0A0D0A0D) {
            p += 4;
            while (*p) *b++ = *p++;
            *b = 0;
            found = 1;
            break;
        }
        p++;
    }
}