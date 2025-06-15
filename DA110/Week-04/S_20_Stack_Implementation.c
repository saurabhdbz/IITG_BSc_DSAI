#include <stdio.h>
#define MAX 100

int A[MAX], TOP = -1;

// Push an element onto the stack
int PUSH(int ele) {
    if (TOP < MAX - 1) {
        TOP++;
        A[TOP] = ele;
        return 1;
    } else {
        return -1;  // Stack overflow
    }
}

// Pop an element from the stack
int POP() {
    if (TOP > -1) {
        int ele = A[TOP];
        TOP--;
        return ele;
    } else {
        return -1;  // Stack underflow
    }
}

// Display all elements in the stack
void display() {
    int i;
    for (i = 0; i <= TOP; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Return the top element of the stack
int TopOfStack() {
    return A[TOP];
}

// Check if the stack is empty
int isEmpty() {
    return (TOP == -1);
}

// Check if the stack is full
int isFull() {
    return (TOP == MAX - 1);
}

// Main function to demonstrate stack operations
int main() {
    PUSH(10);
    PUSH(13);
    PUSH(5);

    printf("POP: %d\n", POP());
    printf("POP: %d\n", POP());
    printf("POP: %d\n", POP());

    return 0;
}
