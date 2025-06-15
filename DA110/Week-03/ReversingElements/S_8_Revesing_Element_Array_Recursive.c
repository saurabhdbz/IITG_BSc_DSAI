#include <stdio.h>

// Recursive function to reverse array elements between i and j
void reverse(int *A, int i, int j) {
    int temp;
    if (i < j) {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        reverse(A, i + 1, j - 1);
    }
}

int main() {
    int A[] = {5, 10, 12, 4, 7, 6, 8, 3, 9, 11};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    // Call reverse from index 0 to n-1
    reverse(A, 0, n - 1);

    printf("\nReversed Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
