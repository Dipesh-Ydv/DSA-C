#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *arr;
};

struct Queue *createQueue(unsigned capacity) {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (int *)malloc(q->capacity * sizeof(int));
    return q;
}

int isFull(struct Queue *q) {
    return (q->size == q->capacity);
}

int isEmpty(struct Queue *q) {
    return (q->size == 0);
}

void enqueue(struct Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full already!\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = item;
    q->size = q->size + 1;
    printf("%d is enqueued to queue\n",item);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty already!\n");
        return;
    }
    int item  = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    printf("%d is dequeued from queue\n",item);
}

int rear(struct Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->arr[q->rear];
}

int front(struct Queue *q) {
    if (isFull(q)) {
        return -1;
    }
    return q->arr[q->front];
}
 
int main ()
{

    struct Queue *q = createQueue(10);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,8);
    enqueue(q,9);
    enqueue(q,10);
    enqueue(q,3);   // At this step OverFlow 

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);    // At this step UnderFlow
    

    // if (isEmpty(q)) {
    //     printf("Queue is Empty");
    // }
    
    return 0;
}