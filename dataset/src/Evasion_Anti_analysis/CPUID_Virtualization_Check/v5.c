#include <windows.h>
#include <intrin.h>

int __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int info[4];
    int state = 5;
    int is_vm = 0;
    while (state != 0) {
        switch (state) {
            case 5:
                __cpuid(info, 1);
                state = 10;
                break;
            case 10:
                is_vm = (info[2] >> 31) & 1;
                state = 0;
                break;
        }
    }
    return is_vm;
}