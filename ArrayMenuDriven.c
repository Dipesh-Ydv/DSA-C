#include<stdio.h>
#include<stdlib.h>

int arr[10];
int size = 0;

void traversal(int arr[]) {
    if (size == 0) {
        printf("Array is empty!\n");
    }

    for (int i = 0; i < size; i++) {
        printf("Element at %d index is : %d\n", i, arr[i]);
    }
}

void insert(int arr[],int element) {
    if (size < 10) {
        arr[size] = element;
        size++;
    } else {
        printf("Array is Full!");
    }
}

void insertAtIndex(int arr[], int index, int element) {
    if (index == size) {
        arr[index] = element;
        size++;
    }
    for (int i = size + 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    size++;
}

void search(int arr[], int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("%d is present at index no : %d",element, i);
            break;
        }
    }
}

void delete(int arr[], int index) {
    for (int i = index; i < size; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main ()
{
    
    // traversal(arr);
    // insert(arr,1);
    // insert(arr,2);
    // insert(arr,3);
    // insert(arr,4);
    // insert(arr,5);
    // insert(arr,6);
    // insertAtIndex(arr,3,56);
    // delete(arr,5);
    // search(arr,4);
    // traversal(arr);
    while (1) {
        int choice;
        printf("\n1. Traversal The Array \n");
        printf("2. Insert \n");
        printf("3. Insert At Given Index \n");
        printf("4. Delete An Index \n");
        printf("5. Search An Element \n");
        printf("6. Exit! \n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        if (choice == 1) {
            printf("\n");
            traversal(arr);
        }
        if (choice == 2) {
            int num;
            printf("\nEnter the element to insert : ");
            scanf("%d",&num);
            insert(arr,num);
        }
        if (choice == 3) {
            int num,index;
            printf("\nEnter the index and element to insert : ");
            scanf("%d%d",&index,&num);
            insertAtIndex(arr, index, num);
        }
        if (choice == 4) {
            int index;
            printf("\nEnter the index to delete : ");
            scanf("%d",&index);
            delete(arr,index);
        }
        if (choice == 5) {
            int num;
            printf("\nEnter the element to search : ");
            scanf("%d",&num);
            search(arr,num);
            printf("\n");
        }
        if (choice == 6) {
            break;
        } 
    }
    return 0;
}