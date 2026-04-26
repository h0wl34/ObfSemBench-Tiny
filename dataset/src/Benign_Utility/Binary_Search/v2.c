#include <stdlib.h>

int __attribute__((noinline)) __attribute__((used)) locate_value_v2(const int *ptr, int n, int val){
    const int *base = ptr;
    while (n > 0) {
        const int *mid = base + (n >> 1);
        if (*mid == val) {
            return (int)(mid - ptr);
        } else if (*mid < val) {
            base = mid + 1;
            n--;
        }
        n >>= 1;
    }
    return -1;
}