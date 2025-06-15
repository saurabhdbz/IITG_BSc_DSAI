#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10, i;
    int *A = (int *)malloc(sizeof(int) * n);

    // Input elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Output elements
    printf("The array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(A);

    return 0;
}
