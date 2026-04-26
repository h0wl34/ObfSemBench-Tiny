#include <stdlib.h>
#include <string.h>

void __attribute__((noinline)) __attribute__((used)) process_data_a(int *arr, int n) {
    if (n < 2) return;
    int m = n / 2;
    process_data_a(arr, m);
    process_data_a(arr + m, n - m);
    int *b = (int *)malloc(n * sizeof(int));
    int i = 0, j = m, k = 0;
    while (i < m && j < n) b[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    while (i < m) b[k++] = arr[i++];
    while (j < n) b[k++] = arr[j++];
    memcpy(arr, b, n * sizeof(int));
    free(b);
}