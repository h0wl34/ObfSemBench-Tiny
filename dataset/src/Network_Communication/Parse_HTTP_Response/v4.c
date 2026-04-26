#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_h_v4(const char* data, char* out){
    int k = 0;
    while(k < 5) { k++; }
    if (k >= 5) {
        const char* s = data;
        while (*s) {
            if (*s == '\r' && *(s+1) == '\n' && *(s+2) == '\r' && *(s+3) == '\n') {
                s += 4;
                while(*s) { *out++ = *s++; }
                *out = 0;
                return 1;
            }
            s++;
        }
    }
    return 0;
}