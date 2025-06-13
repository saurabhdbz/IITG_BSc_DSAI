#include <stdio.h>

int Search(int A[], int ele, int n) {
    int i;
    // Check every element in the collection
    for (i = 0; i < n; i++) {
        if (A[i] == ele)
            return i;  // Return the index if element is found
    }
    return -1;  // Return -1 if element is not found
}

int main() {
    int A[] = {3, 5, 6, 10, 13, 17, 19, 20};
    int n = sizeof(A) / sizeof(A[0]);
    int ele = 13;  // Element to search
    int index = Search(A, ele, n);

    if (index != -1)
        printf("Element %d found at index %d\n", ele, index);
    else
        printf("Element %d not found in the array\n", ele);

    return 0;
}
