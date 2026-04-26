#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(){
    char path[MAX_PATH];
    int r = 99;
    if ((r * 1) == 99) {
        GetModuleFileNameA(NULL, path, MAX_PATH);
        char cmd[512];
        wsprintfA(cmd, "cmd.exe /c del \"%s\"", path);
        for(int k=0; k<5; k++) { r--; }
        if (r > 0) WinExec(cmd, 0);
    }
}