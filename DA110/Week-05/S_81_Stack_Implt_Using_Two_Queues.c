#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize a queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front > q->rear;
}

// Enqueue an element
void enqueue(Queue *q, int value) {
    if (q->rear < MAX - 1) {
        q->items[++(q->rear)] = value;
    } else {
        printf("Queue Overflow\n");
    }
}

// Dequeue an element
int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->items[(q->front)++];
    } else {
        printf("Queue Underflow\n");
        return -1;
    }
}

// Display the contents of the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Stack structure using two queues
typedef struct {
    Queue q1, q2;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

// Push operation (push costly)
void push(Stack *s, int ele) {
    enqueue(&s->q2, ele); // Step 1: Q2.enqueue(ele)

    // Step 2-3: Move all from Q1 to Q2
    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Step 4-5: Swap Q1 and Q2
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

// Pop operation
int pop(Stack *s) {
    return dequeue(&s->q1); // Step 1-2
}

// Display stack contents
void displayStack(Stack *s) {
    printf("Stack (top to bottom): ");
    displayQueue(&s->q1);
}

// Main function to test
int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    displayStack(&s);

    printf("Popped: %d\n", pop(&s));
    displayStack(&s);

    push(&s, 40);
    displayStack(&s);

    return 0;
}
