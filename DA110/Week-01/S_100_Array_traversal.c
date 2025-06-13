#include <stdio.h>

void Display(int A[], int n) {
    int i;
    // Visit every element
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {3, 5, 6, 10, 13, 17, 19, 20};
    int n = sizeof(A) / sizeof(A[0]);

    Display(A, n);

    return 0;
}
