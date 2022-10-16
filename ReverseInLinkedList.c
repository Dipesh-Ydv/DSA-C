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

// Reversing a Linked List using recursion
struct Node *reverseRecursive(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// It will reverse K no of Nodes
struct Node * reverseKNode(struct Node *head, int k) {
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next;
    int count = 0;

    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseKNode(next, k);
    }

    return prev; 
}

void makeCycle(struct Node *head, int pos) {
    struct Node *temp = head;
    struct Node *startNode;
    int count = 1;

    while (temp->next != NULL) {
        if (count == pos) {
            startNode = temp;       // It will store where the new link is going to form
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;     // Now it will link the last Node to the position which is required 
}

int detectCycle(struct Node *head) {
    struct Node *slow = head;   // It will move by one step
    struct Node *fast = head;   // It will move by two steps

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            return 1;
        }
    }
    return 0;
}

void removeCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;

    // Allocates memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second node
    head->data = 3;
    head->next = second;

    // Link second and third node
    second->data = 4;
    second->next = third;

    // Terminate the list at third node
    third->data = 5;
    third->next = fourth;

    fourth->data = 6;
    fourth->next = fifth;

    fifth->data = 7;
    fifth->next = sixth;

    sixth->data = 8;
    sixth->next = NULL;

  
    // printf("Elements before reverse\n");
    // traversal(head);

    // printf("\nElements after reverse\n"); 
    // head = reverseRecursive(head);
    // head = reverseKNode(head, 2);
    // traversal(head);

    makeCycle(head, 2);
    removeCycle(head);

    if(detectCycle(head)) {
        printf("There is a cycle in the List");
    } else {
        printf("There is no cycle");
    }

    return 0;
}