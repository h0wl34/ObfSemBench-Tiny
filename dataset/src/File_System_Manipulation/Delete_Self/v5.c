#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(){
    char path[MAX_PATH];
    char cmd[512];
    int state = 7;
    while (state != 0) {
        switch (state) {
            case 7:
                GetModuleFileNameA(NULL, path, MAX_PATH);
                state = 14;
                break;
            case 14:
                wsprintfA(cmd, "cmd.exe /c del \"%s\"", path);
                state = 21;
                break;
            case 21:
                WinExec(cmd, 0);
                state = 0;
                break;
        }
    }
}