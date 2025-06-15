#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

int main() {
    struct node *head;

    // Create first node
    head = (struct node *)malloc(sizeof(struct node));
    head->info = 3;

    // Create second node
    head->next = (struct node *)malloc(sizeof(struct node));
    head->next->info = 1;

    // Create third node
    head->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->info = 7;

    // End of the list
    head->next->next->next = NULL;

    // Print the elements
    printf("First element: %d\n", head->info);
    printf("Second element: %d\n", head->next->info);
    printf("Third element: %d\n", head->next->next->info);

    return 0;
}
