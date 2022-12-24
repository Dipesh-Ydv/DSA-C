#include<stdio.h>
#include<stdlib.h>

void quikSort(int arr[], int low, int hi) {
    if (low >= hi) {
        return;
    }

    int s = low;
    int e = hi;
    int m = s + (e - s) / 2;
    int pivot = arr[m];

    while (s <= e) {

        while (arr[s] < pivot) {
            s++;
        }

        while (arr[e] > pivot) {
            e--;
        }

        if (s <= e) {
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }

    quikSort(arr, low, e);
    quikSort(arr, s, hi);
}

int main ()
{
    int arr[] = {3, 22, 4, 0, -1, 5};
    quikSort(arr, 0, 6);

    for (int i = 0; i < 6; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}