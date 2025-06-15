#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize a stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push an element
void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop an element
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

// Display stack
void displayStack(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// Queue using two stacks
typedef struct {
    Stack s1, s2;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

// Enqueue operation (costly)
void enqueue(Queue *q, int ele) {
    // Step 1-2: Move all from S1 to S2
    while (!isEmpty(&q->s1)) {
        push(&q->s2, pop(&q->s1));
    }

    // Step 3: Push new element into S2
    push(&q->s2, ele);

    // Step 4-5: Move everything back from S2 to S1
    while (!isEmpty(&q->s2)) {
        push(&q->s1, pop(&q->s2));
    }

    printf("Enqueued: %d\n", ele);
}

// Dequeue operation
int dequeue(Queue *q) {
    if (isEmpty(&q->s1)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return pop(&q->s1);
}

// Display queue contents
void displayQueue(Queue *q) {
    printf("Queue (front to rear): ");
    displayStack(&q->s1);
}

// Test
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    displayQueue(&q);

    enqueue(&q, 40);
    displayQueue(&q);

    return 0;
}
