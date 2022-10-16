#include<stdio.h>
#include<stdlib.h>

struct myArray {
    int totalSize;
    int useSize;
    int* ptr;
};

void createArray(struct myArray *a, int tSize, int uSize) {
    // (*a).totalSize = tSize;
    // (*a).useSize = uSize;
    // (*a).ptr = (int *) malloc(tSize * sizeof(int));

    a->totalSize = tSize;
    a->useSize = uSize;
    a->ptr = (int *) malloc(tSize * sizeof(int));
}

void show (struct myArray *a) {
    for (int i = 0; i < a->useSize; i++) {
        printf("%d\n", (a->ptr)[i]);  // I can use *(a->ptr) also
    }
}
void set (struct myArray *a) {
    int n;
    for (int i = 0; i < a->useSize; i++) {
        printf("Enter element %d : ",i);
        scanf("%d",&n);
        (a->ptr)[i] = n; 
    }
}
void get (struct myArray * a, int index) {
    printf("%d",(a->ptr)[index]);
}

int main () 
{
    struct myArray arr;
    createArray(&arr,10,2);
    set(&arr);
    show(&arr);
    get(&arr,0);

    return 0;
}