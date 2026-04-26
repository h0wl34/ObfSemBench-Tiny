#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(){
    char path[MAX_PATH];
    char cmd[MAX_PATH + 20];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    wsprintfA(cmd, "/c del \"%s\"", path);
    ShellExecuteA(NULL, "open", "cmd.exe", cmd, NULL, SW_HIDE);
}