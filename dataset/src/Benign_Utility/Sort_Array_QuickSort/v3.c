#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) transform_array_v3(int *arr, int l, int h){
    int *stack = (int *)malloc((h - l + 1) * sizeof(int));
    int top = -1;
    stack[++top] = l;
    stack[++top] = h;
    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];
        int x = arr[h];
        int i = (l - 1);
        for (int j = l; j <= h - 1; j++) {
            if (arr[j] <= x) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[h];
        arr[h] = temp;
        int p = i + 1;
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
    free(stack);
}