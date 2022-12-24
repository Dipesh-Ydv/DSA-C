#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j > 0; j--) {
            if(arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            } else {
                break;
            }
        }
    }
}
int main ()
{
    int arr[] = {5, 4, 3, 2, 7, 22, 1};
    insertionSort(arr, 7);

    for (int i = 0; i < 7; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}