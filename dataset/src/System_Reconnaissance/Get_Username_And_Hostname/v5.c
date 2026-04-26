#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(char* user, char* host){
    DWORD s1 = 256, s2 = 256;
    int state = 1;
    while (state != 0) {
        switch (state) {
            case 1:
                GetUserNameA(user, &s1);
                state = 2;
                break;
            case 2:
                GetComputerNameA(host, &s2);
                state = 0;
                break;
        }
    }
}