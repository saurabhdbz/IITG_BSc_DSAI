#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};

int main() {
    struct node *head, *tail;

    // Allocate and initialize the first node
    head = (struct node *)malloc(sizeof(struct node));
    head->info = 3;
    head->prev = NULL;

    // Allocate and link the second node
    head->next = (struct node *)malloc(sizeof(struct node));
    head->next->info = 1;
    head->next->prev = head;

    // Allocate and link the third node
    head->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->info = 7;
    head->next->next->prev = head->next;
    head->next->next->next = NULL;

    // Set tail to the last node
    tail = head->next->next;

    // Optional: print values to verify
    printf("First element: %d\n", head->info);
    printf("Second element: %d\n", head->next->info);
    printf("Third element: %d\n", tail->info);

    return 0;
}
