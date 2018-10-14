#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **, int);
void insertAfter(struct Node *, int);
void append(struct Node **, int);

struct Node *createFromArray(int *, size_t);

void printList(struct Node *);

#endif // LIST_H
