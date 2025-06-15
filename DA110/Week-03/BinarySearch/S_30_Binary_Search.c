#include <stdio.h>

// Function for binary search
int binarySearch(int A[], int n, int ele) {
    int low = 0, high = n - 1, mid = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (A[mid] == ele)
            return mid;
        else if (ele > A[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // Element not found
}

// Driver code to test the binary search
int main() {
    int A[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(A) / sizeof(A[0]);
    int ele = 10;

    int index = binarySearch(A, n, ele);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}
