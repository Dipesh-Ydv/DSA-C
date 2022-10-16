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

void preOrderTraveresal(struct Node *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preOrderTraveresal(root->l);
        preOrderTraveresal(root->r);
    }
}

void postOrderTraversal(struct Node *root) {
    if (root != NULL) {
        postOrderTraversal(root->l);
        postOrderTraversal(root->r);
        printf("%d\t", root->data);
    }
}

void inOrderTraversal(struct Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->l);
        printf("%d\t", root->data);
        inOrderTraversal(root->r);
    }
}

int main() {

    // Creating nodes using function 
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(4);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(6);


    // Linking the nodes p1 and p2 with node p
    p->l = p1;
    p->r = p2;
    p1->l = p3;
    p1->r = p4;

    // preOrderTraveresal(p);
    // postOrderTraversal(p);
    inOrderTraversal(p);

    return 0;
}