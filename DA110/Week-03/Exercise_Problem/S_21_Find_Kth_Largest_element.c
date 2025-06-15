#include <stdio.h>

// Helper function to find the minimum value in the array
int minimum(int A[], int n) {
    int min = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < min) min = A[i];
    }
    return min;
}

// Helper function to find the maximum value in the array
int maximum(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) max = A[i];
    }
    return max;
}

// Function to find the k-th largest element
int kLargest(int A[], int n, int k) {
    int min = minimum(A, n);  // Find the minimum value in the array
    int max = maximum(A, n);  // Find the maximum value in the array

    // Binary search over the value range
    while (min <= max) {
        int avg = min + (max - min) / 2;
        int count = 0;

        // Count how many elements are greater than avg
        for (int i = 0; i < n; i++) {
            if (A[i] > avg) count++;
        }

        // If count >= k, we need to search in the right half (larger values)
        if (count >= k)
            min = avg + 1;
        else
            max = avg - 1;
    }

    // After binary search, min is pointing to the k-th largest value
    return min;
}


int main() {
    int A[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 3;

    int result = kLargest(A, n, k);
    printf("The %d-th largest element is: %d\n", k, result);

    return 0;
}
