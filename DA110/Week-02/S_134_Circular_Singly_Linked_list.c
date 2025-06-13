#include <stdio.h>
#include <stdlib.h>

// Node structure for Circular Singly Linked List
struct node {
    int info;
    struct node *next;
};

int main() {
    struct node *head;

    // Step 1: Create the first node
    head = (struct node *)malloc(sizeof(struct node));
    head->info = 3;
    head->next = head;  // Initially, the list points to itself

    // Step 2: Create the second node
    struct node *second = (struct node *)malloc(sizeof(struct node));
    second->info = 7;
    second->next = head;  // Second node points to the first node

    // Step 3: Link first node to second node
    head->next = second;

    // (Optional) Step 4: Change head to point to the second node (if needed)
    head = second;

    // Traversal to show circular list structure
    struct node *temp = head;
    printf("Circular Linked List Elements:\n");
    do {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != head);

    return 0;
}
