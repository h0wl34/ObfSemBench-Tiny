#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(){
    char str[10];
    int x = 5;
    if (x * x == 25) {
        str[0] = 'a';
        if (x + 2 == 7) str[1] = 'd';
        str[2] = 'v';
        for(int i=0; i<1; i++) str[3] = 'a';
        str[4] = 'p'; str[5] = 'i'; str[6] = '3'; str[7] = '2'; str[8] = 0;
    }
    LoadLibraryA(str);
}