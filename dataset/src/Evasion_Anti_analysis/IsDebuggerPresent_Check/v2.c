#include <windows.h>
#include <intrin.h>

int __attribute__((noinline)) __attribute__((used)) routine_v2(){
    unsigned long long peb = __readgsqword(0x60);
    unsigned char* ptr = (unsigned char*)peb;
    return *(ptr + 2);
}