#include <stdio.h>
#include <stdlib.h>

// Node structure for Circular Singly Linked List
struct node {
    int info;
    struct node *next;
};

// Function to traverse and print elements of the Circular Singly Linked List
void traverse(struct node *hPtr) {
    if (hPtr == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = hPtr;

    // Traverse till we come back to the starting node
    while (ptr->next != hPtr) {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }

    // Print the last node (which points back to head)
    printf("%d\n", ptr->info);
}

int main() {
    struct node *head;

    // Step 1: Create the first node
    head = (struct node *)malloc(sizeof(struct node));
    head->info = 3;
    head->next = head;  // Points to itself to form a circular link

    // Step 2: Create the second node
    struct node *second = (struct node *)malloc(sizeof(struct node));
    second->info = 7;
    second->next = head;  // Points back to first node

    // Step 3: Link the first node to the second
    head->next = second;

    // Optional: Make head point to second (now first in logical order)
    head = second;

    // Traverse the circular linked list
    traverse(head);

    return 0;
}
