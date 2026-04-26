#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(){
    char s[13];
    s[0] = 'k'; s[1] = 'e'; s[2] = 'r'; s[3] = 'n'; s[4] = 'e'; s[5] = 'l';
    s[6] = '3'; s[7] = '2'; s[8] = '.'; s[9] = 'd'; s[10] = 'l'; s[11] = 'l';
    s[12] = '\0';
    LoadLibraryA(s);
}