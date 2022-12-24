#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    char *arr;
};

struct Stack *createStack(unsigned capacity) {
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = (char *)malloc(capacity * sizeof(char));
    return s;
}

int isFull(struct Stack *s) {
    return (s->top == s->capacity - 1);
}

int isEmpty(struct Stack *s) {
    return (s->top==  -1);
}

void push(struct Stack *s, char item) {
    if (isFull(s)) {
        // printf("Stack is already full!\n");
        return;
    }
    s->top += 1;
    s->arr[s->top] = item;
    // printf("%d is pushed into stack\n",item);
}

void pop(struct Stack *s) {
    if (isEmpty(s)) {
        // printf("Underflow!\n");
        return;
    }
    // char item = s->arr[s->top];
    s->top -= 1;
    // free(item);
    // printf("%d is poped from stack\n",item);
}

int parenthesisMatch(char *exp) {
    struct Stack *s = createStack(sizeof(exp));

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(s, '(');
        }
        if (exp[i] == ')') {
            if (isEmpty(s)) {
                return 0;
            }
            pop(s);
        }
    }
    return  (isEmpty(s));
}

int main ()
{
    char *exp = "(1+(2*11))";

    if (parenthesisMatch(exp)) {
        printf("Parenthesis matches");
    } else {
        printf("Parenthesis doesn't matches");
    }

    return 0;
}