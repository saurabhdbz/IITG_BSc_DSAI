#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

void pushFront(int x) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
    printf("Pushed %d to front\n", x);
}

void pushBack(int x) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
    printf("Pushed %d to back\n", x);
}

void popFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    printf("Popped from front: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void popBack() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    printf("Popped from back: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

int getFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -1;
    }
    return deque[front];
}

int getBack() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -1;
    }
    return deque[rear];
}

void display() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Double Ended Queue (Deque) Menu ---\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Pop Front\n");
        printf("4. Pop Back\n");
        printf("5. Display\n");
        printf("6. Front Element\n");
        printf("7. Back Element\n");
        printf("8. Check if Empty\n");
        printf("9. Check if Full\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push at front: ");
                scanf("%d", &value);
                pushFront(value);
                break;
            case 2:
                printf("Enter element to push at back: ");
                scanf("%d", &value);
                pushBack(value);
                break;
            case 3:
                popFront();
                break;
            case 4:
                popBack();
                break;
            case 5:
                display();
                break;
            case 6:
                value = getFront();
                if (value != -1) printf("Front element: %d\n", value);
                break;
            case 7:
                value = getBack();
                if (value != -1) printf("Back element: %d\n", value);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
