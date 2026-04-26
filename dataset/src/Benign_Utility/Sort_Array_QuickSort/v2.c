#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) execute_sort_v2(int *base, int low, int high){
    while (low < high) {
        int *pivot_ptr = base + high;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (*(base + j) <= *pivot_ptr) {
                i++;
                int t = *(base + i);
                *(base + i) = *(base + j);
                *(base + j) = t;
            }
        }
        int t = *(base + i + 1);
        *(base + i + 1) = *(base + high);
        *(base + high) = t;
        int p = i + 1;
        if (p - low < high - p) {
            execute_sort_v2(base, low, p - 1);
            low = p + 1;
        } else {
            execute_sort_v2(base, p + 1, high);
            high = p - 1;
        }
    }
}