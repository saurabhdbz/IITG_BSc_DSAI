#include <stdio.h>
#include <stdlib.h>

// Define the structure
struct node {
    char info;
    struct node *lChild;
    struct node *rChild;
};

// Create a new node
struct node* createNode(char value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->lChild = NULL;
    newNode->rChild = NULL;
    return newNode;
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct node* node) {
    if (node != NULL) {
        inorder(node->lChild);
        printf("%c ", node->info);
        inorder(node->rChild);
    }
}

int main() {
    // Manually creating a few nodes
    struct node* root = createNode('A');
    root->lChild = createNode('B');
    root->rChild = createNode('C');
    root->lChild->lChild = createNode('D');
    root->lChild->rChild = createNode('E');
    root->rChild->rChild = createNode('F');

    printf("Inorder Traversal of the Tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
