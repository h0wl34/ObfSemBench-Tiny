#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int s = 0;
    char b[12];
    while (s != -1) {
        switch (s) {
            case 0: b[0] = 'n'; b[1] = 't'; s = 1; break;
            case 1: b[2] = 'd'; b[3] = 'l'; s = 2; break;
            case 2: b[4] = 'l'; b[5] = '.'; s = 3; break;
            case 3: b[6] = 'd'; b[7] = 'l'; b[8] = 'l'; b[9] = 0; s = 4; break;
            case 4: LoadLibraryA(b); s = -1; break;
        }
    }
}