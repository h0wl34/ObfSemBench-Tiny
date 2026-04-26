#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) calc_product_v3(int *m1, int *m2, int *out, int rows, int cols){
    int i, j, k;
    for (i = 0; i < rows * cols; i++) out[i] = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            for (k = 0; k < rows; k++) {
                *(out + i * cols + j) += *(m1 + i * rows + k) * *(m2 + k * cols + j);
            }
        }
    }
}