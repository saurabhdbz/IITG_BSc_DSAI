#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int n;
};

// Function prototypes
void create(struct Array *arr, int size);
void insert(struct Array *arr, int ele, int index);
int search(struct Array *arr, int ele);
void deleteAt(struct Array *arr, int index);
void display(struct Array *arr);

// Create function
void create(struct Array *arr, int size) {
    arr->A = (int *)malloc(sizeof(int) * size);
    arr->n = 0;
}

// Insert element at index
void insert(struct Array *arr, int ele, int index) {
    int j;
    for (j = arr->n; j > index; j--) {
        arr->A[j] = arr->A[j - 1];
    }
    arr->A[index] = ele;
    arr->n = arr->n + 1;
}

// Search for element
int search(struct Array *arr, int ele) {
    for (int i = 0; i < arr->n; i++) {
        if (arr->A[i] == ele)
            return i;
    }
    return -1;
}

// Delete element at index
void deleteAt(struct Array *arr, int index) {
    for (int j = index; j < arr->n - 1; j++) {
        arr->A[j] = arr->A[j + 1];
    }
    arr->n = arr->n - 1;
}

// Display array
void display(struct Array *arr) {
    for (int i = 0; i < arr->n; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Array X;
    create(&X, 10);

    insert(&X, 5, 0);
    insert(&X, 7, 1);
    insert(&X, 9, 2);

    printf("Array elements:\n");
    display(&X);

    int index = search(&X, 7);
    if (index != -1)
        printf("Element 7 found at index %d\n", index);
    else
        printf("Element 7 not found\n");

    deleteAt(&X, 1);
    printf("Array after deletion:\n");
    display(&X);

    return 0;
}
