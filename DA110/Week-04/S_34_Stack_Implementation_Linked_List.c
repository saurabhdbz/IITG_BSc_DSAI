#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *head;

// Function to initialize the stack
void create(void) {
    head = (struct node *)malloc(sizeof(struct node));
    head->info = 0;       // info field will store size
    head->next = NULL;
}

// Function to push an element onto the stack
void PUSH(int ele) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->info = ele;
    ptr->next = head->next;
    head->next = ptr;
    head->info++; // increment size
}

// Function to pop an element from the stack
int POP(void) {
    struct node *ptr;
    int ele;

    if (head->next != NULL) {
        ptr = head->next;
        head->next = head->next->next;
        head->info--; // decrement size
        ele = ptr->info;
        free(ptr);
        return ele;
    } else {
        return -1; // Stack is empty
    }
}

// Function to check if the stack is empty
int isEmpty(void) {
    return (head->next == NULL);
}

// Function to get current stack size
int size(void) {
    return head->info;
}

// Function to display the stack elements
void display(void) {
    struct node *ptr = head->next;
    printf("Stack: ");
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    create();

    PUSH(10);
    PUSH(5);
    PUSH(8);

    display(); // Stack: 8 5 10

    printf("Popped: %d\n", POP()); // Popped: 8

    display(); // Stack: 5 10

    printf("Size: %d\n", size()); // Size: 2

    return 0;
}
