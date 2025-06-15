#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node *next;
};

// Function to reverse the linked list
void reverse(struct node **head) {
    struct node *prev = NULL;
    struct node *cur = *head;
    struct node *next = NULL;

    while (cur != NULL) {
        next = cur->next;    // Save next node
        cur->next = prev;    // Reverse pointer
        prev = cur;          // Move prev forward
        cur = next;          // Move cur forward
    }

    *head = prev; // Update head to new first node
}

// Helper function to insert at the end
void insert(struct node **head, int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Helper function to print the list
void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to demonstrate reversal
int main() {
    struct node *head = NULL;

    // Create list: 5 -> 10 -> 15 -> 20
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 10);
    insert(&head, 3);
    insert(&head, 30);
    insert(&head, 15);
    insert(&head, 7);
    insert(&head, 20);

    printf("Original List:\n");
    printList(head);

    reverse(&head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}
