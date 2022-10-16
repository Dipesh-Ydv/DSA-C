#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *r;
    struct Node *l;
};

struct Node *createNode (int data) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->l = NULL;
    n->r = NULL;

    return n;
}

int main ()
{
    /* 
    // This method is causing repetition

    // Constructing the root node
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = 2;
    p->l = NULL;
    p->r = NULL;

    // Constructing the second node
    struct Node *p1 = (struct Node *)malloc(sizeof(struct Node));
    p1->data = 3;
    p1->l = NULL;
    p1->r = NULL;

    // Constructing the third node
    struct Node *p2 = (struct Node *)malloc(sizeof(struct Node));
    p2->data = 4;
    p2->l = NULL;
    p2->r = NULL;

    */

    // Creating nodes using function 
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(4);

    // Linking the nodes p1 and p2 with node p
    p->l = p1;
    p->r = p2;

    return 0;
}