#include <windows.h>
#include <stdint.h>

__attribute__((noinline)) __attribute__((used))
int routine_v2(int* arr, int size, int target) {
    volatile int* start = arr;
    volatile int* end = arr + size - 1;
    volatile int* mid_ptr;
    volatile int result = -1;

    while (start <= end) {
        mid_ptr = start + ((end - start) >> 1);
        if (*mid_ptr == target) {
            result = (int)(mid_ptr - arr);
            break;
        }
        if (*mid_ptr < target) {
            start = mid_ptr + 1;
        } else {
            end = mid_ptr - 1;
        }
    }
    return result;
}