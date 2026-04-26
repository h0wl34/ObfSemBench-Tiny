#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(char* u, char* h){
    unsigned int su = 256;
    unsigned int sh = 256;
    unsigned int* psu = &su;
    unsigned int* psh = &sh;
    GetUserNameA((char*)u, (LPDWORD)psu);
    GetComputerNameA((char*)h, (LPDWORD)psh);
}