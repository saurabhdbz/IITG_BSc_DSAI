#include <stdio.h>
#include <stdlib.h>

// Recursive function to find minimum
int findMin(int *A, int n, int idx, int min) {
    if (idx == n)
        return min;
    if (A[idx] < min)
        min = A[idx];
    return findMin(A, n, idx + 1, min);
}

int main() {
    int n = 8, i, min;
    int *data = (int *)malloc(sizeof(int) * n);

    // Input values
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &data[i]);

    // Call recursive function
    min = findMin(data, n, 1, data[0]);

    printf("Minimum number: %d\n", min);

    // Free memory
    free(data);

    return 0;
}
