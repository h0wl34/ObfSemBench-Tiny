#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(void* p){
    unsigned char b[sizeof(SYSTEM_INFO)];
    GetSystemInfo((LPSYSTEM_INFO)b);
    for (int i = 0; i < sizeof(SYSTEM_INFO); i++) {
        *((unsigned char*)p + i) = *(b + i);
    }
}