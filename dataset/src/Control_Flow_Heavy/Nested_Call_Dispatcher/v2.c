#include <windows.h>

typedef void (*handler)(void*);

static __attribute__((always_inline)) void op_c(void* p) {
    *(int*)p ^= 0x55;
}

static __attribute__((always_inline)) void op_b(void* p) {
    unsigned char* ptr = (unsigned char*)p;
    size_t addr = (size_t)op_c;
    handler next = (handler)(addr ^ 0);
    *ptr = (*ptr << 2) | (*ptr >> 6);
    next(p);
}

static __attribute__((always_inline)) void op_a(void* p) {
    void* funcs[1];
    funcs[0] = (void*)op_b;
    handler next = (handler)(*(void**)((unsigned char*)funcs + 0));
    *(int*)p += 0x1337;
    next(p);
}

void __attribute__((noinline)) __attribute__((used)) routine_v2(int* state) {
    void* base[1];
    base[0] = (void*)op_a;
    handler start = (handler)(*(void**)((uintptr_t)base & ~0x0));
    start(state);
}