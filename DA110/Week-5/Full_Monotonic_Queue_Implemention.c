#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
    int isIncreasing;  // 1 for increasing, 0 for decreasing
} MonotonicQueue;

// Initialize the queue
void initQueue(MonotonicQueue *q, int isIncreasing) {
    q->front = 0;
    q->rear = -1;
    q->isIncreasing = isIncreasing;
}

// Check if the queue is empty
int isEmpty(MonotonicQueue *q) {
    return (q->front > q->rear);
}

// Push an element while maintaining monotonicity
void push(MonotonicQueue *q, int value) {
    // Remove elements from the rear that violate monotonic property
    while (!isEmpty(q) &&
          ((q->isIncreasing && value < q->data[q->rear]) ||
           (!q->isIncreasing && value > q->data[q->rear]))) {
        q->rear--;
    }
    q->rear++;
    q->data[q->rear] = value;
}

// Pop the front element (usually done when it's out of window range)
void pop(MonotonicQueue *q, int value) {
    if (!isEmpty(q) && q->data[q->front] == value) {
        q->front++;
    }
}

// Get the front (minimum or maximum depending on type)
int top(MonotonicQueue *q) {
    if (!isEmpty(q)) {
        return q->data[q->front];
    } else {
        printf("Queue is empty.\n");
        return -1;
    }
}

// Display current elements
void display(MonotonicQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Monotonic Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

// Example driver code
int main() {
    MonotonicQueue mq;

    int type;
    printf("Choose queue type:\n1. Increasing (min at front)\n2. Decreasing (max at front)\n");
    scanf("%d", &type);

    initQueue(&mq, type == 1 ? 1 : 0);

    int choice, val;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Top\n4. Display\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&mq, val);
                break;
            case 2:
                printf("Enter value to pop (only if at front): ");
                scanf("%d", &val);
                pop(&mq, val);
                break;
            case 3:
                val = top(&mq);
                if (val != -1)
                    printf("Top element: %d\n", val);
                break;
            case 4:
                display(&mq);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
