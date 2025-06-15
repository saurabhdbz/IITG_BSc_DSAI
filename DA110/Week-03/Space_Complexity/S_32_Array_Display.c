#include <stdio.h>
#include <stdlib.h>

// Function to display elements of the array
void display(int *A, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int n = 10, i;
    int *A = (int *)malloc(sizeof(int) * n);

    // Input elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Display elements
    display(A, n);

    // Free allocated memory
    free(A);

    return 0;
}
