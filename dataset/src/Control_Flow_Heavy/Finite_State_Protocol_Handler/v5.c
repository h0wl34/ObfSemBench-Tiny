#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const unsigned char* data, int len){
    int s = 0;
    int i = 0;
    while (i < len) {
        switch (s) {
            case 0:
                s = (data[i] == 0xAA) ? 1 : 0;
                i++;
                break;
            case 1:
                s = (data[i] == 0xBB) ? 2 : 0;
                i++;
                break;
            case 2:
                s = 0;
                i++;
                break;
        }
    }
}