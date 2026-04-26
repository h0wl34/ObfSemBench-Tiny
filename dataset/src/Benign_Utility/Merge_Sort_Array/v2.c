#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) process_and_sort_b(int *arr, int n) {
    if (n <= 1) return;

    int *tmp = (int *)malloc(n * sizeof(int));
    if (!tmp) return; // защита на случай malloc failure

    // Имитируем рекурсию с помощью внутренней функции через указатели на массив
    int l = 0, r = n - 1;

    // Простейшая рекурсивная сортировка с использованием массива и временного буфера
    typedef struct { int l, r; } Range;
    Range stack[64]; // достаточно для глубины рекурсии log2(n) <= 64
    int top = 0;
    stack[top++] = (Range){l, r};

    while (top > 0) {
        Range cur = stack[--top];
        l = cur.l;
        r = cur.r;
        if (r - l < 1) continue;
        int m = l + (r - l) / 2;

        // push right and left halves
        stack[top++] = (Range){l, m};
        stack[top++] = (Range){m + 1, r};

        // merge
        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r) tmp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
        while (i <= m) tmp[k++] = arr[i++];
        while (j <= r) tmp[k++] = arr[j++];
        for (i = l; i <= r; i++) arr[i] = tmp[i];
    }

    free(tmp);
}