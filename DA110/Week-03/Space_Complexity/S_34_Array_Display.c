#include <stdio.h>
#include <stdlib.h>

// Function to perform linear search
int search(int *A, int n, int ele) {
    int i;
    for (i = 0; i < n; i++) {
        if (A[i] == ele)
            return i;  // Element found at index i
    }
    return -1;  // Element not found
}

int main() {
    int n = 10, i, flag;
    int *A = (int *)malloc(sizeof(int) * n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Search for element 5
    flag = search(A, n, 5);

    // Output result
    if (flag == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", flag);

    // Free the allocated memory
    free(A);

    return 0;
}
