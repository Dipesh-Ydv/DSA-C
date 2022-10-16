#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void traversal (struct Node *head) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;

    while (ptr != NULL) {
        printf("Element is : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void getIndex (struct Node *head, int element) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    int i = 0;
    
    while (ptr->data != element) {
        ptr = ptr->next;
        i++;
    }
    printf("Index of %d is : %d\n", element, i);
}

struct Node * insertAtFirst (struct Node *head, int element) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = element;
    ptr->prev = NULL;
    return ptr;

}

struct Node * insertAtLast (struct Node *head, int element) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = element;

    while(p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->prev = p;

    return head;
}

struct Node * insertAtIndex (struct Node *head, int index, int element) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    ptr->data = element;
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;

    return head;

}

int main ()
{
    
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;
    head->prev = NULL;

    second->data = 3;
    second->next = third;
    second->prev = head;

    third->data = 4;
    third->next = fourth;
    third->prev = second;

    fourth->data = 5;
    fourth->next = NULL;
    fourth->prev = third;

    printf("List before insertion :\n");
    traversal(head);
    // head = insertAtFirst(head, 1);
    // head = insertAtLast(head, 6);
    head = insertAtIndex(head, 2, 44);
    printf("\nList after insertion :\n");
    traversal(head);
    // getIndex(head, 4);


    
    return 0;
}