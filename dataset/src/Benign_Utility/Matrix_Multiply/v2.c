#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) perform_mult_v2(int n, double *a, double *b, double *c){
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            double r = a[i * n + k];
            for (int j = 0; j < n; j++) {
                c[i * n + j] += r * b[k * n + j];
            }
        }
    }
}