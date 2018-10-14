#include "array.h"

#include <stdio.h>

void printArray(int_array arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int_array generateRange(int start, int end) {
    int_array arr;
    if (end < start) {
        return NULL;
    } else if (end == start) {
        arr = malloc(sizeof(int));
        *arr = start;
    } else {
        arr = malloc((end - start) * sizeof(int));
        for (int i = start; i < end; ++i) {
            arr[i - start] = i;
        }
    }
    return arr;
}