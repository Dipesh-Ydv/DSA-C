#include <stdio.h>
#include <stdlib.h>

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

void printIndex (struct Node * head, int index) {
    struct Node *p = head;
    int i = 0;

    while (i != index) {
        p = p->next;
        i++;
    }
    printf("%d", p->data);
}

struct Node * insertAtFirst (struct Node * head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node * insertAtIndex (struct Node * head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index-1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertAtEnd (struct Node * head, int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node * insertAfterNode (struct Node *head, struct Node *prevNode, int data) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

struct Node * reverse(struct Node * head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    return prev;
}

struct Node *reverseRecursive(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
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
    third->next = NULL;

    // printf("Elements before insertion\n");
    printf("Elements before reverse\n");
    traversal(head);
    // head = insertAtFirst(head,1 );
    // head = insertAtIndex(head,1,1);
    // printf("\nElements after insertion\n");
    printf("\nElements after reverse\n");
    // head = insertAtEnd(head, 6);
    // head = insertAfterNode(head, second, 8);
    // head = reverse(head);
    head = reverseRecursive(head);
    traversal(head);

    return 0;
}