#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(){
    char p[260];
    char c[300];
    char* pp = p;
    char* pc = c;
    GetModuleFileNameA(0, pp, 260);
    char s[] = {0x2f,0x63,0x20,0x64,0x65,0x6c,0x20,0x22,0x00};
    int i = 0;
    while(s[i]) *(pc + i) = s[i], i++;
    int j = 0;
    while(*(pp + j)) *(pc + i + j) = *(pp + j), j++;
    *(pc + i + j) = 0x22; *(pc + i + j + 1) = 0;
    WinExec(pc, 0);
}