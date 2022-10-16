#include<stdio.h>

void insert (int arr[], int capacity, int size, int index, int element) {
    if (index >= capacity) {
        printf("Capacoty of array is full");
    }
    
    for (int i = size + 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
}
int main ()
{
    int arr[200] = {1,2,5,6,7,8};
    int size = 6;
    insert(arr,200,size,3,44);
    size += 1;
    insert(arr,200,size,5,11);
    size += 1;
    insert(arr,200,size,0,4);
    size += 1;
    for(int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}