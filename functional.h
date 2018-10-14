#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#define TRUE 1
#define FALSE 0

#include "array.h"
#include "list.h"

// Types
typedef int bool_t;

typedef int (*MapFunc)(int);
typedef int (*ReduceFunc)(int, int);
typedef bool_t (*FilterFunc)(int);

// Functions
void mapList(struct Node *, MapFunc);
void mapArray(int *, size_t, MapFunc);

int reduceList(struct Node *, ReduceFunc);
int reduceArray(int *, size_t, ReduceFunc);

struct Node *filterList(struct Node *, FilterFunc);
int *filterArray(int *, size_t, FilterFunc);

#endif // FUNCTIONAL_H
