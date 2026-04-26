#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) process_data_v1(int *items, int left, int right){
    int i, j, pivot, temp;
    if (left < right) {
        pivot = left;
        i = left;
        j = right;
        while (i < j) {
            while (items[i] <= items[pivot] && i < right)
                i++;
            while (items[j] > items[pivot])
                j--;
            if (i < j) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
        temp = items[pivot];
        items[pivot] = items[j];
        items[j] = temp;
        process_data_v1(items, left, j - 1);
        process_data_v1(items, j + 1, right);
    }
}