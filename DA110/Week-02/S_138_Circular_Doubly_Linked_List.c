#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int info;
    struct node *next;
    struct node *prev;
};

int main() {
    // Step 1: Create the head node
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->info = 3;
    head->next = head;   // Initially points to itself (circular)
    head->prev = head;

    // Step 2: Create the second node
    struct node *second = (struct node *)malloc(sizeof(struct node));
    second->info = 7;

    // Step 3: Update links for circular doubly linkage
    second->next = head;       // Second node points to head
    second->prev = head;       // Second node comes after head
    head->next = second;       // Head's next is second
    head->prev = second;       // Head's prev is second

    // Optional: Print list forward and backward to verify
    printf("Forward Traversal: ");
    struct node *temp = head;
    do {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != head);

    printf("\nBackward Traversal: ");
    temp = head->prev;  // Start from last node
    do {
        printf("%d ", temp->info);
        temp = temp->prev;
    } while (temp != head->prev);

    return 0;
}
