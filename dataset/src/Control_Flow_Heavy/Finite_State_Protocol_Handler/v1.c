#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const unsigned char* data, int len){
    int state = 0;
    for (int i = 0; i < len; i++) {
        if (state == 0 && data[i] == 0xAA) state = 1;
        else if (state == 1 && data[i] == 0xBB) state = 2;
else __attribute__((noinline)) __attribute__((used)) if(state == 2){
            unsigned char payload = data[i];
            state = 0;
        }
    }
}