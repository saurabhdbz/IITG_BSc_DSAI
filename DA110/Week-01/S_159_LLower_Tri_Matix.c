#include <stdio.h>

int main() {
    int i, j, k = 0, n = 5;
    int B[25];  // Array to store non-zero elements

    printf("Enter elements of %dx%d Left Lower Triangular Matrix (only i >= j positions):\n", n, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i >= j) {
                scanf("%d", &B[k]);
                k++;
            }
        }
    }

    // Display the stored 1D array of non-zero elements
    printf("Stored non-zero elements in 1D array:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    return 0;
}
