#include <string.h>
#include "functional.h"

void mapList(struct Node *head, MapFunc func) {
    head->data = func(head->data);
    if (head->next) {
        mapList(head->next, func);
    }
}

void mapArray(int *arr, size_t arrSize, MapFunc func) {
    for (size_t i = 0; i < arrSize; ++i) {
        arr[i] = func(arr[i]);
    }
}

int reduceArray(int *arr, size_t arrSize, ReduceFunc func) {
    if (arrSize == 1) {
        return func(*arr, 0);
    }
    return func(*arr, reduceArray(arr + 1, arrSize - 1, func));
}

int reduceList(struct Node *head, ReduceFunc func) {
    if (!head->next) {
        return func(head->data, 0);
    }
    return func(head->data, reduceList(head->next, func));
}

struct Node *filterList(struct Node *head, FilterFunc func) {
    struct Node *new = malloc(sizeof(struct Node));
    if (!head->next) {
        return (func(head->data)) ? head : NULL;
    }
    if (func(head->data)) {
        memcpy(new, head, sizeof(struct Node));
        new->next = filterList(head->next, func);
    } else {
        new = filterList(head->next, func);
    }
    return new;
}
