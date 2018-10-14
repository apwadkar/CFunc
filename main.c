#include <stdio.h>
#include <assert.h>

#include "functional.h"

// Map functions
int addTwo(int a) { return a + 2; }
int mulTwo(int a) { return a * 2; }

// Reduce functions
int sumAll(int d, int a) { return d + a; }
int mulAll(int d, int a) { return d * a; }

// Filter functions
bool_t lessThanTwo(int d) { return d <= 2; }
bool_t moreThanFive(int d) { return d > 2; }

int main(void) {
    // Variables
    int *arr = generateRange(0, 10);
    struct Node *list = createFromArray(arr, 10);
    printList(list);

    // Reduce list: Sums all numbers
    int red = reduceList(list, &sumAll);
    printf("Sum (Reduced): %d\n", red);

    // Filter list: Less than or equal to two
    struct Node *filter = filterList(list, &moreThanFive);
    printList(filter);

    // Map list: Adds two to numbers
    mapList(filter, &mulTwo);
    printList(filter);

    // Reduce list: Sums all numbers
    red = reduceList(filter, &mulAll);
    printf("Sum (Map & Reduced): %d\n", red);
    return 0;
}
