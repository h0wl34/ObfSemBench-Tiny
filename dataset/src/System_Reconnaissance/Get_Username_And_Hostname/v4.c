#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(char* user, char* host){
    int g = 0;
    if (g + 100 > 50) {
        DWORD s1 = 256, s2 = 256;
        GetUserNameA(user, &s1);
        for (int i = 0; i < 5; i++) g += i;
        if (g >= 0) GetComputerNameA(host, &s2);
    }
}