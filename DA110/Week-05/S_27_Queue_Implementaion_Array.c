#include <stdio.h>

#define MAX 10
int storage[MAX];
int Head = -1, Tail = -1;

// Check if queue is empty
int isEmpty() {
    return (Tail == -1);
}

// Check if queue is full
int isFull() {
    return (Tail == MAX - 1);
}

// Enqueue operation
void enQueue(int ele) {
    if (isFull()) {
        printf("Queue Full\n");
        return;
    }

    if (Head == -1) Head = 0;  // First element enqueued

    storage[++Tail] = ele;
    printf("Enqueued %d successfully\n", ele);
}

// Dequeue operation (shifts all elements left)
int deQueue() {
    int i, tmp;

    if (isEmpty()) {
        printf("Queue Empty\n");
        return -1;
    }

    tmp = storage[Head];

    // Shift all elements to the left
    for (i = Head; i < Tail; i++) {
        storage[i] = storage[i + 1];
    }

    Tail--;

    // If queue becomes empty
    if (Tail < Head) {
        Head = -1;
        Tail = -1;
    }

    return tmp;
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements: ");
    for (int i = Head; i <= Tail; i++) {
        printf("%d ", storage[i]);
    }
    printf("\n");
}

// Main function to test
int main() {
    enQueue(5);
    enQueue(10);
    display();
    printf("Dequeued: %d\n", deQueue());
    printf("Dequeued: %d\n", deQueue());
    enQueue(8);
    enQueue(3);
    enQueue(2);
    display();

    printf("Dequeued: %d\n", deQueue());
    display();

    enQueue(40);
    display();

    return 0;
}
