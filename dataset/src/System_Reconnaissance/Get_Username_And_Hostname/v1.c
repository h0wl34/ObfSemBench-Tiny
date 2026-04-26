#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(char* user, char* host){
    DWORD uSize = 256;
    DWORD hSize = 256;
    GetUserNameA(user, &uSize);
    GetComputerNameA(host, &hSize);
}