#include <stdio.h>
#include <stdlib.h>

// Function to find and print the maximum number
void findMax(int *data, int n) {
    int max = data[0];
    for (int i = 1; i < n; i++) {
        if (max < data[i])
            max = data[i];
    }
    printf("Maximum number: %d\n", max);
}

int main() {
    int n = 8, i;
    int *data = (int *)malloc(sizeof(int) * n);

    // Input values
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &data[i]);

    // Call the function
    findMax(data, n);

    // Free memory
    free(data);

    return 0;
}
