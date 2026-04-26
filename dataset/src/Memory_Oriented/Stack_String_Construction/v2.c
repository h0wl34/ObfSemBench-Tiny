#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(){
    unsigned long long part1 = 0x32336C656E72656B; 
    unsigned int part2 = 0x6C6C642E;
    char s[16];
    char* p = s;
    *((unsigned long long*)p) = part1;
    *((unsigned int*)(p + 8)) = part2;
    *(p + 12) = (char)(part2 >> 32); 
    LoadLibraryA(s);
}