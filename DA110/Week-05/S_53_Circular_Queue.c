#include <stdio.h>

#define MAX 10
int storage[MAX];
int Head = 0, Tail = 0;

// Check if the queue is empty
int isEmpty() {
    return (Head == Tail);
}

// Check if the queue is full
int isFull() {
    return ((Tail + 1) % MAX == Head);
}

// Enqueue operation
void enQueue(int ele) {
    if (!isFull()) {
        storage[Tail] = ele;
        Tail = (Tail + 1) % MAX;
        printf("Enqueued %d successfully\n", ele);
    } else {
        printf("Queue Full\n");
    }
}

// Dequeue operation
int deQueue(void) {
    if (!isEmpty()) {
        int ele = storage[Head];
        Head = (Head + 1) % MAX;
        return ele;
    } else {
        printf("Queue Empty\n");
        return -1;
    }
}

// Display function
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements: ");
    int i = Head;
    while (i != Tail) {
        printf("%d ", storage[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main for demonstration
int main() {
    enQueue(10);
    enQueue(20);
    enQueue(30);
    display();

    printf("Dequeued: %d\n", deQueue());
    display();

    enQueue(40);
    enQueue(50);
    display();

    return 0;
}
