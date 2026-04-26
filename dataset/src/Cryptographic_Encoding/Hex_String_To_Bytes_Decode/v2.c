#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_d_v2(char* s, unsigned char* b){
    while (*s) {
        unsigned char h = *s > '9' ? (*s & ~0x20) - 'A' + 10 : *s - '0';
        s++;
        unsigned char l = *s > '9' ? (*s & ~0x20) - 'A' + 10 : *s - '0';
        s++;
        *b++ = (h << 4) | l;
    }
}