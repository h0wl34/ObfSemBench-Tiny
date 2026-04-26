#include <windows.h>
#include <stdint.h>

typedef void (*step)(int*, int);

static void step_final(int* v, int junk) {
    if (((junk * junk) + 1) > 0) {
        *v += 5;
    } else {
        *v -= 999;
    }
}

static inline void step_mid(int* v, int junk) {
    int x = 10;
    for (int i = 0; i < 5; i++) x += i;
    if (x > 2) {
        step next = step_final;
        *v *= 2;
        next(v, x);
    }
}

static inline void step_init(int* v, int junk) {
    int a = 5;
    int b = 10;
    if ((a + b) == 15 || (a * b) == 1) {
        step next = step_mid;
        *v -= 10;
        next(v, a);
    }
}

void __attribute__((noinline)) __attribute__((used)) routine_v4(int* output) {
    int key = 0xDEADBEEF;

    volatile int dummy = 0;
    dummy += (int)step_final;
    dummy += (int)step_mid;
    dummy += (int)step_init;

    if ((key & 1) || !(key & 1)) {
        step start = step_init;
        start(output, key);
    }

    (void)dummy; 
}