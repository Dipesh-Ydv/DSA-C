#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *arr;
};

struct Queue *createQueue(unsigned capacity) {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0 ,q->rear = -1;
    q->size = 0;
    q->arr = (int *)malloc(q->capacity * sizeof(int));
    return q;
}

int isEmpty(struct Queue *q) {
    return (q->size == 0);
}

int isFull(struct Queue *q) {
    return (q->rear == q->capacity - 1);
}

void enqueue(struct Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is already Full!\n");
        return;
    }
    q->rear = q->rear + 1;
    q->arr[q->rear] = item;
    q->size = q->size + 1;
    printf("%d is enqueued in queue\n",item);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is already empty!\n");
        return;
    }
    int item = q->arr[q->front];
    q->front = q->front + 1;
    q->size = q->size - 1;
    printf("%d is dequeued from queue\n",item);
}

// int size()

int main ()
{
    struct Queue *q = createQueue(10);
    enqueue(q, 1);
    enqueue(q, 2);

    dequeue(q);
    dequeue(q);

    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);
    
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    // enqueue(q, 12);
    // enqueue(q, 13);

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    return 0;
}