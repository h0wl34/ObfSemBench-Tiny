#include <windows.h>

typedef void (*next_func)(int*);

static __attribute__((always_inline)) void level_3(int* val) {
    *val += 30;
}

static __attribute__((always_inline)) void level_2(int* val) {
    next_func f = level_3;
    *val += 20;
    f(val);
}

static __attribute__((always_inline)) void level_1(int* val) {
    next_func f = level_2;
    *val += 10;
    f(val);
}

void __attribute__((noinline)) __attribute__((used)) routine_v1(int* data) {
    next_func f = level_1;
    f(data);
}
