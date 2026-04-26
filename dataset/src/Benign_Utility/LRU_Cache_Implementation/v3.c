#include <string.h>

int __attribute__((noinline)) __attribute__((used)) manage_cache_c(int *keys, int *vals, int *n, int cap, int k, int v) {
    int idx = -1;
    for (int i = 0; i < *n; i++) if (keys[i] == k) { idx = i; break; }
    if (idx != -1) {
        int res = (v == -1) ? vals[idx] : v;
        int tk = keys[idx], tv = res;
        memmove(keys + 1, keys, idx * sizeof(int));
        memmove(vals + 1, vals, idx * sizeof(int));
        keys[0] = tk; vals[0] = tv;
        return res;
    }
    if (v == -1) return -1;
    int count = *n;
    if (count == cap) count--;
    memmove(keys + 1, keys, count * sizeof(int));
    memmove(vals + 1, vals, count * sizeof(int));
    keys[0] = k; vals[0] = v;
    if (*n < cap) (*n)++;
    return v;
}