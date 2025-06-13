#include <stdio.h>

// Function to delete element at index i
void delete(int *A, int i, int *n) {
    int j;

    // Validate index
    if (i < 0 || i >= *n) {
        printf("Invalid index\n");
        return;
    }

    // Step 1: Shift all elements after index i one position left
    for (j = i; j < *n - 1; j++) {
        A[j] = A[j + 1];
    }

    // Step 2: Decrease the number of elements (UB = UB - 1)
    *n = *n - 1;
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
    int n = 8;    // Number of elements in array
    int index = 3; // Index to delete (deleting element 10)

    printf("Original array:\n");
    display(A, n);

    delete(A, index, &n);

    printf("Array after deleting element at index %d:\n", index);
    display(A, n);

    return 0;
}
