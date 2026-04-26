#include <stdlib.h>

int __attribute__((noinline)) __attribute__((used)) manage_cache_a(int *keys, int *vals, long *ticks, int cap, int k, int v, long now) {
    int lru = 0;
    for (int i = 0; i < cap; i++) {
        if (keys[i] == k) {
            ticks[i] = now;
            if (v != -1) vals[i] = v;
            return vals[i];
        }
        if (ticks[i] < ticks[lru]) lru = i;
    }
    if (v != -1) {
        keys[lru] = k;
        vals[lru] = v;
        ticks[lru] = now;
    }
    return -1;
}