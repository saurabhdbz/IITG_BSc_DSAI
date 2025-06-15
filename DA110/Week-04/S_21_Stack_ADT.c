#include <stdio.h>
#include <stdlib.h>

// Define the Stack ADT using struct
struct Stack {
    int TOP;
    int *A;
    int MAX;
};

// Initialize the stack with given size
void initStack(struct Stack *s, int size) {
    s->TOP = -1;
    s->MAX = size;
    s->A = (int *)malloc(sizeof(int) * size);
}

// Push an element into the stack
int PUSH(struct Stack *s, int ele) {
    if (s->TOP < s->MAX - 1) {
        s->TOP++;
        s->A[s->TOP] = ele;
        return 1; // success
    } else {
        return -1; // stack overflow
    }
}

// Pop an element from the stack
int POP(struct Stack *s) {
    if (s->TOP > -1) {
        int ele = s->A[s->TOP];
        s->TOP--;
        return ele;
    } else {
        return -1; // stack underflow
    }
}

// Return the top of stack without popping
int TopOfStack(struct Stack *s) {
    if (s->TOP > -1)
        return s->A[s->TOP];
    else
        return -1; // empty
}

// Display all elements in the stack
void display(struct Stack *s) {
    for (int i = 0; i <= s->TOP; i++) {
        printf("%d ", s->A[i]);
    }
    printf("\n");
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->TOP == -1;
}

// Check if stack is full
int isFull(struct Stack *s) {
    return s->TOP == s->MAX - 1;
}

// Main function to demonstrate stack ADT
int main() {
    struct Stack s;
    initStack(&s, 100);

    PUSH(&s, 10);
    PUSH(&s, 13);
    PUSH(&s, 5);

    display(&s);

    printf("Popped: %d\n", POP(&s));
    printf("Popped: %d\n", POP(&s));
    printf("Top of stack: %d\n", TopOfStack(&s));

    return 0;
}
