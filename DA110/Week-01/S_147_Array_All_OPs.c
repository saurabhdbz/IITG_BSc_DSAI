#include <stdio.h>

// Function to search for an element in the array
int search(int A[], int ele, int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] == ele)
            return i;
    }
    return -1;
}

// Function to insert an element at a specific index
void insert(int *A, int ele, int i, int *n) {
    for (int j = *n; j > i; j--) {
        A[j] = A[j - 1];
    }
    A[i] = ele;
    *n = *n + 1;
}

// Function to delete an element at a specific index
void delete(int *A, int i, int *n) {
    for (int j = i; j < *n - 1; j++) {
        A[j] = A[j + 1];
    }
    *n = *n - 1;
}

// Function to update the value at a specific index
void update(int *A, int i, int ele) {
    A[i] = ele;
}

// Function to display the array
void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Main function to test all operations
int main() {
    int n = 5;
    int A[100] = {3, 10, 4, 6, 7};  // Enough space for insertions

    // Search for 10
    int index = search(A, 10, n);
    printf("Index of 10: %d\n", index);

    // Insert 15 at index 3
    insert(A, 15, 3, &n);

    // Delete element at index 2
    delete(A, 2, &n);

    // Display final array
    printf("Final array:\n");
    display(A, n);

    return 0;
}
