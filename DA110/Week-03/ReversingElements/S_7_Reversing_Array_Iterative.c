#include <stdio.h>

void reverse(int *A, int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = A[i];
        A[i] = A[n - i - 1];
        A[n - i - 1] = temp;
    }
}

int main() {
    int A[] = {5, 10, 12, 4, 7, 6, 8, 3, 9, 11};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    reverse(A, n); // Call reverse function

    printf("\nReversed Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
