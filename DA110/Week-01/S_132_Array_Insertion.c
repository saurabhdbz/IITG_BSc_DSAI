#include <stdio.h>

// Function to insert an element at index i
void insert(int *A, int ele, int i, int *n) {
    int j;

    // Step 1: Free the index i for the new element by shifting elements
    for (j = *n; j > i; j--) {
        A[j] = A[j - 1];
    }

    // Step 2: Insert the element at index i
    A[i] = ele;

    // Step 3: Update the number of elements
    *n = *n + 1;
}

// Function to display the array
void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[100] = {3, 5, 6, 10, 13, 17, 19, 20};  // Original array
    int n = 8;        // Current number of elements (UB = 7)
    int ele = 15;     // Element to insert
    int index = 3;    // Arbitrary index i ≥ 0

    printf("Original array:\n");
    display(A, n);

    insert(A, ele, index, &n);

    printf("Array after inserting %d at index %d:\n", ele, index);
    display(A, n);

    return 0;
}
