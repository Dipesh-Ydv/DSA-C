#include<stdio.h>
#include<stdlib.h>

int getMaxIndex(int arr[], int start, int end) {
    int max = start;
    for (int i = start; i <= end; i++) {
        if (arr[max] < arr[i]) {
            max = i;
        }
    }
    return max;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int last = size - i - 1;
        int maxIndex = getMaxIndex(arr, 0, last);

        int temp = arr[maxIndex];
        arr[maxIndex] = arr[last];
        arr[last] = temp;
    }
}

int main ()
{
    int arr[] = {5, 3, 10, 2, 0, -1};
    selectionSort(arr, 6);

    for (int i = 0; i < 6; i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}