#include <stdio.h>

#define SIZE 100

typedef struct {
    int arr[SIZE];
    int F;
    int R;
} Queue;

void initQueue(Queue* q) {
    q->F = -1;
    q->R = -1;
}

int isEmpty(Queue* q) {
    return q->F == -1 || q->F > q->R;
}

void enqueue(Queue* q, int value) {
    if (q->R == SIZE - 1) return;
    if (q->F == -1) q->F = 0;
    q->arr[++q->R] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->F++];
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->F; i <= q->R; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void reverse(Queue* q) {
    if (isEmpty(q)) return;
    int val = dequeue(q);
    reverse(q);
    enqueue(q, val);
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    display(&q);
    reverse(&q);
    display(&q);

    return 0;
}