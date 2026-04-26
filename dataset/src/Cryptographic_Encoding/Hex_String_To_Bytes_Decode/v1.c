#include <windows.h>
#include <stdio.h>

void __attribute__((noinline)) __attribute__((used)) routine_d_v1(const char* hex, BYTE* bin){
    size_t len = strlen(hex);
    for (size_t i = 0; i < len; i += 2) {
        sscanf(hex + i, "%2hhx", bin + (i / 2));
    }
}