#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int info;
    struct node *next;
};

// Function to insert a node at the end of the list
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

// Recursive function to find the minimum value in the list
int findMin(struct node *ptr, int min) {
    if (ptr == NULL) return min;

    if (min > ptr->info)
        return findMin(ptr->next, ptr->info);
    else
        return findMin(ptr->next, min);
}

// Optional: display the list
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

    if (head != NULL) {
        int minVal = findMin(head, head->info);
        printf("Minimum value (recursive): %d\n", minVal);
    } else {
        printf("List is empty.\n");
    }

    return 0;
}
