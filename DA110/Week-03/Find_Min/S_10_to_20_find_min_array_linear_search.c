#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum value in the array
void findMin(int *data, int n) {
    int i, min;
    min = data[0];  // Assume the first element is minimum

    // Traverse the array to find the actual minimum
    for (i = 1; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }

    printf("Minimum number: %d\n", min);
}

int main() {
    int n = 8, i;
    int *data = (int *)malloc(sizeof(int) * n);

    // Input from user
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Call function to find minimum
    findMin(data, n);

    // Free the allocated memory
    free(data);

    return 0;
}
