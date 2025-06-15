#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
struct Node {
    int data;
    struct Node* next;
};

// Define pointers for head (front) and tail (rear) of the queue
struct Node* head = NULL;
struct Node* tail = NULL;

// Enqueue operation: add an element to the end of the queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (tail == NULL) {
        // Queue is empty
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    printf("%d enqueued to queue.\n", value);
}

// Dequeue operation: remove an element from the front of the queue
int dequeue() {
    if (head == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value = head->data;
    struct Node* temp = head;
    head = head->next;

    if (head == NULL) {
        // Queue becomes empty
        tail = NULL;
    }

    free(temp);
    return value;
}

// Peek operation: return the front element
int peek() {
    if (head == NULL) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }

    return head->data;
}

// Display operation: print all elements
void display() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu (Linked List) ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                value = peek();
                if (value != -1)
                    printf("Front element: %d\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
