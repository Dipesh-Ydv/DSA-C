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

void inOrderTraversal(struct Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->l);
        printf("%d\t", root->data);
        inOrderTraversal(root->r);
    }
}

struct Node * search(struct Node *root, int target) {
    if (root == NULL) {
        return NULL;
    }
    if (target == root->data) {
        return root;
    } else if (target < root->data) {
        return search(root->l, target);
    } else {
        return search(root->r, target); 
    }
}

void insert(struct Node *root, int data) {
    struct Node *prev = NULL;           // It will always hold the previous value
    while (root != NULL) {
        prev = root;
        if (data == root->data) {
            printf("Not able to insert!");
            return;
        } else if (data < root->data) {
            root = root->l;
        } else {
            root = root->r;
        }
    }
    struct Node * new = createNode(data);
    if (data < prev->data) {
        prev->l = new;
    } else {
        prev->r = new;
    }
}

struct Node * searchIterative(struct Node *root, int target) {
    while (root != NULL) {
        if (root->data == target) {
            return root;
        } else if (root->data < target) {
            root = root->l;
        } else {
            root = root->r;
        }
    }
    return NULL;
}

struct Node *inOrderPredecessor(struct Node *root) {
    root = root->l;
    while (root->r != NULL) {
        root = root->r;
    }
    return root;
}

struct Node * delete(struct Node *root, int value) {
    struct Node *iPre;
    if (root == NULL) {
        return NULL;
    }
    if (root->l == NULL && root->r == NULL) {
        free(root);
        return NULL;
    }
    if (value < root->data) {
        root->l = delete(root->l , value);
    } else if (value > root->data) {
        root->r = delete(root->r, value);
    } else {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->l = delete(root->l, iPre->data);
    }
    return root;
}

int main ()
{
    struct Node *p = createNode(50);
    struct Node *p1 = createNode(40);
    struct Node *p2 = createNode(60);
    struct Node *p3 = createNode(20);
    struct Node *p4 = createNode(45);
    struct Node *p5 = createNode(55);
    struct Node *p6 = createNode(70);

    p->l = p1;
    p->r = p2;
    p1->l = p3;
    p1->r = p4;
    p2->l = p5;
    p2->r = p6;

    // inOrderTraversal(p);

    // struct Node *n = searchIterative(p, 50);;
     
    // if (n != NULL) {
    //     printf("Found : %d\n", n->data);
    // } else {
    //     printf("Element Not Found");
    // }
    
    insert(p, 51);
    insert(p, 56);

    inOrderTraversal(p);
    printf("\n");

    delete(p, 50);
    inOrderTraversal(p);

    return 0;
}