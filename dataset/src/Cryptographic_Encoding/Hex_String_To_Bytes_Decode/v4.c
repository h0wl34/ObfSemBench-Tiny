#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_d_v4(const char* s, BYTE* b){
    int dummy = 0;
    for(int j=0; j<10; j++) dummy += j;
    
    while (*s && (dummy >= 0)) {
        BYTE n = 0;
        for(int k=0; k<2; k++) {
            char c = *s++;
            if (c >= '0' && c <= '9') n = (n << 4) | (c - '0');
            else n = (n << 4) | (c - 'a' + 10);
        }
        *b++ = n;
        if (dummy < 0) break;
    }
}