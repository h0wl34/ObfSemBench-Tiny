#include <windows.h>
#include <stdint.h>

typedef void (*node_fn)(int*, void*);
typedef DWORD (WINAPI *pGetTickCountFn)(void);

static void term_node(int* a, void* p) {
    pGetTickCountFn fn = (pGetTickCountFn)GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetTickCount");
    if (fn) {
        *a ^= (int)fn();
    }
}

static inline void intermediate_node(int* a, void* p) {
    node_fn next = (node_fn)p;
    *a *= 3;
    next(a, NULL);
}

static inline void entry_node(int* a, void* p) {
    node_fn next = intermediate_node;
    *a += 100;
    next(a, (void*)term_node);
}

void __attribute__((noinline)) __attribute__((used)) routine_v3(int* seed) {
    node_fn start = entry_node;
    start(seed, NULL);
}