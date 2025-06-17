#include <stdio.h>
#include <stdlib.h>

// Define the structure
struct node {
    char info;
    struct node *lChild;
    struct node *rChild;
};

// Function to create a new node
struct node* createNode(char data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->info = data;
    newNode->lChild = NULL;
    newNode->rChild = NULL;
    return newNode;
}

// Binary Search Tree Insert
struct node* insert(struct node* root, char data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->info)
        root->lChild = insert(root->lChild, data);
    else
        root->rChild = insert(root->rChild, data);
    return root;
}

// Inorder traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->lChild);
        printf("%c ", root->info);
        inorder(root->rChild);
    }
}

// Preorder traversal
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%c ", root->info);
        preorder(root->lChild);
        preorder(root->rChild);
    }
}

// Postorder traversal
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->lChild);
        postorder(root->rChild);
        printf("%c ", root->info);
    }
}

// Free all nodes
void deleteTree(struct node* root) {
    if (root != NULL) {
        deleteTree(root->lChild);
        deleteTree(root->rChild);
        free(root);
    }
}

// Main with menu
int main() {
    struct node* root = NULL;
    int choice;
    char element;

    while (1) {
        printf("\n\n====== Binary Tree Menu ======\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline after int

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%c", &element);
                root = insert(root, element);
                printf("Inserted '%c' successfully.", element);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                deleteTree(root);
                printf("Tree deleted. Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
