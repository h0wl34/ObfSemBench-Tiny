#include <stdlib.h>
#include <string.h>

void __attribute__((noinline)) __attribute__((used)) process_data_c(int *arr, int n) {
    int *b = (int *)malloc(n * sizeof(int));
    for (int s = 1; s < n; s *= 2) {
        for (int l = 0; l < n; l += 2 * s) {
            int m = l + s, r = l + 2 * s;
            if (m > n) m = n;
            if (r > n) r = n;
            int i = l, j = m, k = l;
            while (i < m && j < r) b[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
            while (i < m) b[k++] = arr[i++];
            while (j < r) b[k++] = arr[j++];
            for (int x = l; x < r; x++) arr[x] = b[x];
        }
    }
    free(b);
}