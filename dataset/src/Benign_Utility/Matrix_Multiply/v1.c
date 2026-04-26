#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) compute_mat_v1(int n, int a[10][10], int b[10][10], int res[10][10]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}