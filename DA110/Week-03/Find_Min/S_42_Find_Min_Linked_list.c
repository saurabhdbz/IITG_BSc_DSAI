#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct node {
    int info;
    struct node *next;
};

// Function to insert a node at the end
void insertLast(struct node **head, int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = val;
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

// Function to find minimum value in the list
int findMin(struct node *ptr) {
    if (ptr == NULL) {
        printf("List is empty.\n");
        return -1; // or INT_MAX as a sentinel value
    }

    int min = ptr->info;
    ptr = ptr->next;

    while (ptr != NULL) {
        if (min > ptr->info)
            min = ptr->info;
        ptr = ptr->next;
    }

    return min;
}

// Optional: function to display the list
void traverse(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int n, i, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        insertLast(&head, val);
    }

    printf("Linked List: ");
    traverse(head);

    int minVal = findMin(head);
    printf("Minimum value in the list: %d\n", minVal);

    return 0;
}
