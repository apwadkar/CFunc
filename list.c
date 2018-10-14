#include "list.h"

#include <stdio.h>

void push(struct Node **headRef, int data) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = *headRef;
    headRef = &new;
}

void insertAfter(struct Node *prev, int data) {
    if (prev) {
        struct Node *new = malloc(sizeof(struct Node));
        new->data = data;
        new->next = prev->next;
        prev->next = new;
    }
}

void append(struct Node **headRef, int data) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;

    struct Node *last = *headRef;
    if (!*headRef) {
        *headRef = new;
    } else {
        while (last->next) {
            last = last->next;
        }
        last->next = new;
    }
}

struct Node *createFromArray(int *arr, size_t size) {
    struct Node *head = NULL;
    append(&head, arr[0]);
    struct Node *iter = head;
    for (size_t i = 1; i < size; ++i) {
        insertAfter(iter, arr[i]);
        iter = iter->next;
    }
    return head;
}

void printList(struct Node *head) {
    printf("%d ", head->data);
    if (head->next) {
        printList(head->next);
    } else {
        printf("\n");
    }
}
