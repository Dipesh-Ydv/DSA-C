#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node * head)
{
    struct Node *p = head;
    do {
        printf("Element : %d\n", p->data);
        p = p->next;
    } while (p!= head);

}
struct Node * insertAtFirst (struct Node * head, int element) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = element;

    struct Node* p = head->next;

    while (p->next != head) {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr; 

    return head;
}

struct Node * insertAtLast (struct Node * head, int element) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = element;

    struct Node* p = head->next;
    
    return head;
}

int main()
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
    third->next = head;

    printf("Circular Linked List before insertion\n");
    traversal(head);
    printf("\nCircular Linked List after insertion\n");
    head = insertAtFirst(head, 2);
    head = insertAtFirst(head, 1);
    traversal(head);

    return 0;
}