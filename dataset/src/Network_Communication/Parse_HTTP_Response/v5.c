#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_h_v5(const char* r, char* b){
    int state = 1;
    int i = 0;
    while (state != 0) {
        switch (state) {
            case 1:
                if (r[i] == '\r' && r[i+1] == '\n' && r[i+2] == '\r' && r[i+3] == '\n') state = 2;
                else if (r[i] == 0) state = 0;
                else i++;
                break;
            case 2:
                i += 4;
                state = 3;
                break;
            case 3:
                if (r[i] == 0) state = 0;
                else {
                    *b = r[i];
                    b++; i++;
                }
                break;
        }
    }
    *b = 0;
}