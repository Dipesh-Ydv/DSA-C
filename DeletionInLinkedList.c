#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void printIndex (struct Node * head, int index) {
    struct Node *p = head;
    int i = 0;

    while (i != index) {
        p = p->next;
        i++;
    }
    printf("%d", p->data);
}

void traversal (struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteFromFirst (struct Node * head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct Node * deleteFromIndex (struct Node *head, int index) {
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++) {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head ;
}

struct Node * deleteFromEnd (struct Node *head) {
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL) {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);

    return head;  
}

struct Node * deleteGivenElement(struct Node *head, int element) {
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != element && q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    if (q->data == element) {
        p->next = q->next;
        free(q);
    } else {
        printf("Element not found in list\n  ");
    }

    return head ;
}

int main ()
{
    struct Node *head = createNode(1);
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));


    // head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;


    printf("Before Deleting\n");
    traversal(head);
    printf("\nAfter Deteting\n");
    // head = deleteFromFirst(head);
    // head = deleteFromIndex(head, 2);
    // head = deleteFromEnd(head); 
    head = deleteGivenElement(head,5); 
    traversal(head);
    // printIndex(head, 1);

    return 0;
}