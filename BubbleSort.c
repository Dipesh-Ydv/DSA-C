#include<stdio.h>

void bubbleSort(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - i; j++) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}
int main ()
{
    int arr[] = {5, 3, 10, 2, 0, -1};
    bubbleSort(arr, 6);

    for (int i = 0; i < 6; i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}