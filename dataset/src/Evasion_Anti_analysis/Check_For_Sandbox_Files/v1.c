#include <windows.h>

int __attribute__((noinline)) __attribute__((used)) routine_v1(){
    const char* paths[] = { "C:\\windows\\System32\\Drivers\\Vmmouse.sys", "C:\\windows\\System32\\Drivers\\vboxguest.sys" };
    for (int i = 0; i < 2; i++) {
        if (GetFileAttributesA(paths[i]) != INVALID_FILE_ATTRIBUTES) return 1;
    }
    return 0;
}