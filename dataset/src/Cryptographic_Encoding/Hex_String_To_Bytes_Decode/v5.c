#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_d_v5(const char* hex, BYTE* bin){
    int state = 1;
    int i = 0;
    BYTE val = 0;
    while (state != 0) {
        switch (state) {
            case 1:
                if (hex[i] == '\0') state = 0;
                else state = 2;
                break;
            case 2:
                if (hex[i] >= '0' && hex[i] <= '9') val = (hex[i] - '0') << 4;
                else val = (hex[i] - 'a' + 10) << 4;
                state = 3;
                break;
            case 3:
                i++;
                if (hex[i] >= '0' && hex[i] <= '9') val |= (hex[i] - '0');
                else val |= (hex[i] - 'a' + 10);
                *bin = val;
                bin++;
                i++;
                state = 1;
                break;
        }
    }
}