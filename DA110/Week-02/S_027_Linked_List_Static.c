#include <stdio.h>

struct node {
    int info;
    int next;
};

int main() {
    int head = 5;
    struct node list[10];

    // First node
    list[head].info = 3;
    list[head].next = 2;

    // Second node
    list[list[head].next].info = 1;
    list[list[head].next].next = 8;

    // Third node
    list[list[list[head].next].next].info = 7;
    list[list[list[head].next].next].next = -1;  // Indicates end of list

    // Print the elements
    printf("First element: %d\n", list[head].info);
    printf("Second element: %d\n", list[list[head].next].info);
    printf("Third element: %d\n", list[list[list[head].next].next].info);

    return 0;
}
