#include <stdio.h>
#include <stdlib.h>

// Define structure for doubly linked list node
struct node {
    int info;
    struct node *prev;
    struct node *next;
};

// Global head and tail pointers
struct node *head = NULL, *tail = NULL;

// Traverse the list from head to tail
void traverse() {
    struct node *ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

// Search for a node with given value
void search(int ele) {
    struct node *ptr = head;
    while(ptr != NULL) {
        if(ptr->info == ele) {
            printf("Found\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("Not Found\n");
}

// Insert at the beginning
void insertFirst(int ele) {
    // Step 1: Create a new node
    struct node *nPtr = (struct node *)malloc(sizeof(struct node));
    nPtr->info = ele;
    nPtr->prev = NULL;
    nPtr->next = head;

    // Step 2: Connect new node with existing head
    if(head != NULL)
        head->prev = nPtr;
    else
        tail = nPtr; // First node if list was empty

    // Step 3: Update head
    head = nPtr;
}

// Insert at the end
void insertLast(int ele) {
    // Step 1: Create a new node
    struct node *nPtr = (struct node *)malloc(sizeof(struct node));
    nPtr->info = ele;
    nPtr->next = NULL;
    nPtr->prev = tail;

    // Step 2: Connect new node to tail
    if(tail != NULL)
        tail->next = nPtr;
    else
        head = nPtr; // First node if list was empty

    // Step 3: Update tail
    tail = nPtr;
}

// Insert at a specific position
void insertPosition(int ele, int pos) {
    if(pos <= 1) {
        insertFirst(ele);
        return;
    }

    // Step 1: Create a new node
    struct node *nPtr = (struct node *)malloc(sizeof(struct node));
    nPtr->info = ele;
    nPtr->next = NULL;
    nPtr->prev = NULL;

    struct node *ptr = head;
    int cnt = 1;

    // Step 2: Traverse to the (pos-1)th node
    while(cnt < pos-1 && ptr != NULL) {
        ptr = ptr->next;
        cnt++;
    }

    // Step 3: Handle insertion
    if(ptr == NULL || ptr->next == NULL) {
        insertLast(ele);
        return;
    }

    // Step 4: Update links
    nPtr->next = ptr->next;
    nPtr->prev = ptr;
    ptr->next->prev = nPtr;
    ptr->next = nPtr;
}

// Delete from the beginning
int deleteFirst() {
    if(head == NULL) return -1;

    // Step 1: Save data and pointer
    int data = head->info;
    struct node *temp = head;

    // Step 2: Move head to next node
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    else
        tail = NULL; // List became empty

    // Step 3: Free old head
    free(temp);
    return data;
}

// Delete from the end
int deleteLast() {
    if(tail == NULL) return -1;

    // Step 1: Save data and pointer
    int data = tail->info;
    struct node *temp = tail;

    // Step 2: Move tail to previous node
    tail = tail->prev;
    if(tail != NULL)
        tail->next = NULL;
    else
        head = NULL; // List became empty

    // Step 3: Free old tail
    free(temp);
    return data;
}

// Delete from a specific position
int deletePosition(int pos) {
    if(pos <= 1)
        return deleteFirst();

    struct node *ptr = head;
    int cnt = 1;

    // Step 1: Traverse to the desired position
    while(cnt < pos && ptr != NULL) {
        ptr = ptr->next;
        cnt++;
    }

    // Step 2: Handle invalid position
    if(ptr == NULL)
        return -1;

    // Step 3: Save data
    int data = ptr->info;

    // Step 4: Adjust pointers
    if(ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    if(ptr->prev != NULL)
        ptr->prev->next = ptr->next;

    // Step 5: Update head or tail if needed
    if(ptr == head)
        head = ptr->next;
    if(ptr == tail)
        tail = ptr->prev;

    // Step 6: Free node
    free(ptr);
    return data;
}

// Sample usage
int main() {
    insertFirst(10);
    insertLast(20);
    insertFirst(5);
    insertPosition(15, 2); // Insert 15 at position 2
    traverse(); // Output: 5 15 10 20

    search(10); // Found
    search(100); // Not Found

    deleteFirst(); // Deletes 5
    deleteLast(); // Deletes 20
    deletePosition(2); // Deletes 10
    traverse(); // Output: 15

    return 0;
}
