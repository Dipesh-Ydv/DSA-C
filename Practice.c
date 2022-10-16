#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void print(struct Node *head, int index) {
    struct Node *ptr = head;

    int i = 0;

    while (i != index) {
        ptr = ptr->next;
        i++;
    }
    
    printf("%d\n",ptr->data);
    
}

struct Node *insertAtStart(struct Node *head, int element) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;
    ptr->next = head;
    return ptr;
}

struct Node *insertAtLast(struct Node *head, int element) {
    struct Node *ptr2 = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;
    ptr->next = NULL;
    
    while (ptr2->next != NULL) {
        ptr2 = ptr2->next;
    }
    ptr2->next = ptr;

    return head;
}

int main ()
{ 

    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocates memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second node
    head->data = 3;
    head->next = second;

    // Link second and third node
    second->data = 4;
    second->next = third;

    // Terminate the list at third node
    third->data = 5;
    third->next = NULL;

    // print(head,5);
    traversal(head);
    head = insertAtStart(head,1);
    head = insertAtLast(head, 6);
    traversal(head);
    // print(head,0);
    
    return 0;
}