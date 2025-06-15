// Array ADT using C
#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;   // Total allocated size
    int n;      // Current number of elements
};

// Constructor: Initialize array with given size
void initArray(struct Array *arr, int s) {
    arr->size = s;
    arr->A = (int *)malloc(sizeof(int) * s);
    arr->n = 0;
}

// Get element at index i
int element(struct Array *arr, int i) {
    if (i >= 0 && i < arr->n)
        return arr->A[i];
    else {
        printf("Invalid index.\n");
        return -1;
    }
}

// Insert element at index i
void insert(struct Array *arr, int ele, int i) {
    if (i >= 0 && i <= arr->n && arr->n < arr->size) {
        for (int j = arr->n; j > i; j--)
            arr->A[j] = arr->A[j - 1];
        arr->A[i] = ele;
        arr->n++;
    } else {
        printf("Insertion failed.\n");
    }
}

// Delete element at index i
void removeAt(struct Array *arr, int i) {
    if (i >= 0 && i < arr->n) {
        for (int j = i; j < arr->n - 1; j++)
            arr->A[j] = arr->A[j + 1];
        arr->n--;
    } else {
        printf("Deletion failed.\n");
    }
}

// Display all elements
void display(struct Array *arr) {
    for (int i = 0; i < arr->n; i++)
        printf("%d ", arr->A[i]);
    printf("\n");
}

// Destructor: Free memory
void destroyArray(struct Array *arr) {
    free(arr->A);
    arr->A = NULL;
    arr->size = 0;
    arr->n = 0;
}

int main() {
    int n;
    printf("What is the size of the collection? - ");
    scanf("%d", &n);

    struct Array data;
    initArray(&data, n);

    int ele;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ele);
        insert(&data, ele, i);
    }

    printf("You entered: ");
    display(&data);

    int min = element(&data, 0);
    for (int i = 1; i < data.n; i++) {
        int val = element(&data, i);
        if (val < min)
            min = val;
    }

    printf("Minimum element is: %d\n", min);

    destroyArray(&data);
    return 0;
}
