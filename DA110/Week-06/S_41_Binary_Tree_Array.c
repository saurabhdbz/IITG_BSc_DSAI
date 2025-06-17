#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char tree[MAX];

// Initialize the tree with empty markers
void initTree() {
    for (int i = 0; i < MAX; i++)
        tree[i] = '-'; // using '-' to indicate empty position
}

// Insert element at given index
void insert(char element, int index) {
    if (index >= MAX) {
        printf("Index out of bounds.\n");
        return;
    }
    if (tree[index] != '-') {
        printf("Position already occupied.\n");
        return;
    }
    tree[index] = element;
    printf("Inserted '%c' at index %d\n", element, index);
}

// Display the tree
void displayTree() {
    printf("\nTree (Index : Value):\n");
    for (int i = 0; i < MAX; i++) {
        if (tree[i] != '-') {
            printf("[%d] : %c\n", i, tree[i]);
        }
    }
}

// Get index of left child
int leftChild(int index) {
    return 2 * index + 1;
}

// Get index of right child
int rightChild(int index) {
    return 2 * index + 2;
}

int main() {
    int choice, index;
    char element;

    initTree();

    printf("Binary Tree using Array Representation\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Root\n");
        printf("2. Insert Left Child\n");
        printf("3. Insert Right Child\n");
        printf("4. Display Tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                if (tree[0] != '-') {
                    printf("Root already exists.\n");
                    break;
                }
                printf("Enter root element: ");
                scanf("%c", &element);
                insert(element, 0);
                break;

            case 2:
                printf("Enter parent index: ");
                scanf("%d", &index);
                if (tree[index] == '-') {
                    printf("Parent does not exist.\n");
                    break;
                }
                printf("Enter left child element: ");
                getchar();
                scanf("%c", &element);
                insert(element, leftChild(index));
                break;

            case 3:
                printf("Enter parent index: ");
                scanf("%d", &index);
                if (tree[index] == '-') {
                    printf("Parent does not exist.\n");
                    break;
                }
                printf("Enter right child element: ");
                getchar();
                scanf("%c", &element);
                insert(element, rightChild(index));
                break;

            case 4:
                displayTree();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
