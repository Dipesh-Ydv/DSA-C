#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int top;
    int size;
    unsigned capacity;
    int *arr;
};

struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->size = 0;
    stack->arr = (int *)malloc(capacity * sizeof(int));

    return stack;
}

int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

int isFull(struct Stack *s) {
    return (s->top == s->capacity - 1);
}

void push(struct Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is already full!\n");
        return;
    }
    s->top += 1;
    s->arr[s->top] = item;
    s->size += 1;
    printf("%d is pushed into stack\n",item);
}

int peek(struct Stack *s) {
    return s->arr[s->top];
}

void pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Underflow!\n");
        return;
    }
    int item = s->arr[s->top];
    s->top -= 1;
    s->size -= 1;
    printf("%d is poped from stack\n",item);
}

int size(struct Stack *s) {
    return s->size;
}

int main ()
{
   
    struct Stack *s = createStack(5);
    push(s, 1);
    push(s, 3);
    push(s, 4);

    pop(s);
    pop(s);
    // pop(s);
    
    int c = size(s);
    printf("%d",c);

    if (isEmpty(s)) {
        printf("\nStack is empty");
    }

    return 0;
}