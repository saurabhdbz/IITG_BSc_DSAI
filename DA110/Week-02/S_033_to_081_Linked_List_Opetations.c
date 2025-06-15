#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node *next;
};

// Head pointer for the list
struct node *head = NULL;

// Traverse and print all elements
void traverse(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

// Search for an element in the list
int search(struct node *ptr, int ele) {
    while (ptr != NULL) {
        if (ptr->info == ele) {
            printf("Found\n");
            return 1;
        }
        ptr = ptr->next;
    }
    printf("Not Found\n");
    return 0;
}

// Insert as first node
void insertFirst(struct node **hPtr, int ele) {
    struct node *nPtr = (struct node *)malloc(sizeof(struct node));
    nPtr->info = ele;
    nPtr->next = (*hPtr);
    (*hPtr) = nPtr;
}

// Insert as last node
void insertLast(struct node *hPtr, int ele) {
    struct node *ptr, *nPtr = (struct node *)malloc(sizeof(struct node));
    nPtr->info = ele;
    nPtr->next = NULL;

    ptr = hPtr;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = nPtr;
}

// Insert at a given position
void insertPosition(struct node **hPtr, int ele, int pos) {
    struct node *ptr, *nPtr = (struct node *)malloc(sizeof(struct node));
    nPtr->info = ele;
    nPtr->next = NULL;

    if (pos == 1) {
        nPtr->next = (*hPtr);
        (*hPtr) = nPtr;
    } else {
        int cnt = 1;
        ptr = (*hPtr);
        while (cnt < pos - 1 && ptr != NULL) {
            ptr = ptr->next;
            cnt++;
        }

        if (ptr == NULL) {
            printf("Position is beyond the range\n");
            free(nPtr);
        } else {
            nPtr->next = ptr->next;
            ptr->next = nPtr;
        }
    }
}

// Delete first node
int deleteFirst(struct node **hPtr) {
    if (*hPtr == NULL) return -1;
    struct node *ptr = *hPtr;
    int data = ptr->info;
    *hPtr = (*hPtr)->next;
    free(ptr);
    return data;
}

// Delete last node
int deleteLast(struct node *hPtr) {
    if (hPtr == NULL) return -1;

    struct node *cur = hPtr;
    struct node *prev = NULL;

    // Only one node
    if (cur->next == NULL) {
        int data = cur->info;
        free(cur);
        head = NULL;
        return data;
    }

    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }

    prev->next = NULL;
    int data = cur->info;
    free(cur);
    return data;
}

// Delete node at a given position
int deletePosition(struct node **hPtr, int pos) {
    struct node *cur = *hPtr;
    struct node *prev = NULL;
    int cnt = 1;

    if (pos == 1 && cur != NULL) {
        int data = cur->info;
        *hPtr = cur->next;
        free(cur);
        return data;
    }

    while (cnt < pos && cur != NULL) {
        prev = cur;
        cur = cur->next;
        cnt++;
    }

    if (cur == NULL) {
        printf("Position out of range.\n");
        return -1;
    }

    prev->next = cur->next;
    int data = cur->info;
    free(cur);
    return data;
}

// Main function to demonstrate functionality
int main() {
    printf("Creating list...\n");

    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertFirst(&head, 30);

    printf("List after insertFirst: ");
    traverse(head);

    insertLast(head, 5);
    printf("List after insertLast: ");
    traverse(head);

    insertPosition(&head, 15, 3);
    printf("List after insert at position 3: ");
    traverse(head);

    printf("Searching for 20: ");
    search(head, 20);

    printf("Deleting first node: %d\n", deleteFirst(&head));
    printf("List after deleting first: ");
    traverse(head);

    printf("Deleting last node: %d\n", deleteLast(head));
    printf("List after deleting last: ");
    traverse(head);

    printf("Deleting node at position 2: %d\n", deletePosition(&head, 2));
    printf("List after deleting at position 2: ");
    traverse(head);

    return 0;
}
