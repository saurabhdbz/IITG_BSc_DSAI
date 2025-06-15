#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int info;
    struct node *next;
};

// Head pointer for the top of the stack
struct node *head = NULL;

// PUSH: Insert element at the beginning
void PUSH(int ele) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    ptr->info = ele;
    ptr->next = head;
    head = ptr;
}

// POP: Remove and return element from the beginning
int POP(void) {
    struct node *temp;
    int ele;

    if (head != NULL) {
        temp = head;
        ele = head->info;
        head = head->next;
        free(temp);
        return ele;
    } else {
        return -1; // Stack empty
    }
}

// isEmpty: Check if the stack is empty
int isEmpty(void) {
    return (head == NULL);
}

// size: Count the number of elements in the stack
int size(void) {
    int cnt = 0;
    struct node *ptr = head;
    while (ptr != NULL) {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

// display: Print all stack elements
void display(void) {
    struct node *ptr = head;
    printf("Stack: ");
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

// main function for demonstration
int main() {
    PUSH(10);
    PUSH(20);
    PUSH(30);
    display();              // Stack: 30 20 10
    printf("Popped: %d\n", POP());  // Popped: 30
    display();              // Stack: 20 10
    printf("Size: %d\n", size());   // Size: 2
    printf("Is Empty: %s\n", isEmpty() ? "Yes" : "No"); // No
    return 0;
}
