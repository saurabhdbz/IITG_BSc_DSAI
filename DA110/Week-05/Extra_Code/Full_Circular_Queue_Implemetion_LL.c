#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node* next;
};

// Head points to front, tail to rear
struct Node* head = NULL;
struct Node* tail = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return head == NULL;
}

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (isEmpty()) {
        head = tail = newNode;
        newNode->next = head; // circular link to itself
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head; // maintain circular link
    }

    printf("%d enqueued to circular queue.\n", value);
}

// Dequeue operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value;
    if (head == tail) {
        // Only one node in queue
        value = head->data;
        free(head);
        head = tail = NULL;
    } else {
        struct Node* temp = head;
        value = head->data;
        head = head->next;
        tail->next = head;
        free(temp);
    }

    return value;
}

// Peek at the front element
int peek() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }
    return head->data;
}

// Display the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu (Linked List) ---\n");
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

    return 0;
}
