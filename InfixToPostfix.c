#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack {
    int top;
    unsigned capacity;
    char *arr;
};

struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char *)malloc(capacity * sizeof(char));

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
        return;
    }
    s->top += 1;
    s->arr[s->top] = item;
}

int peek(struct Stack *s) {
    return s->arr[s->top];
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        return 0;
    }
    char item = s->arr[s->top];
    s->top -= 1;
    return item;
}
int isoperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+') {
        return 1;
    }
    if (ch == '-') {
        return 1;
    }
    if (ch == '*') {
        return 3;
    }
    if (ch == '/') {
        return 3;
    }
    return 0;
}

char  *convert(char *infix) {
    char *postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));
    struct Stack *s = createStack(sizeof(infix));
    int i = 0;
    int j = 0;

    while (infix[i] != '\0') {

        if (!isoperator(infix[i])) {
            postfix[j] = infix[i];
            i++;
            j++;
        } else {
            if (precedence(infix[i]) > precedence(peek(s))) {
                push(s, infix[i]);
                i++;
            } else {
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while (!isEmpty(s)) {
        postfix[j] = pop(s);
        j++;
    }
    return postfix;
}

int main ()
{
    
    char *infix = "a-b+t/6";
    char *postfix = convert(infix);
    for (int i = 0; i < 7; i++) {
        printf("%c",*(postfix + i));
    }
    return 0;
}