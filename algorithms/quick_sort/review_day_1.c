#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoare_partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    do {
        do {
            i++;
        } while (arr[i] <= pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            return j;
        }
    } while (i < j);
    
    return j;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int p = hoare_partition(arr, low, high);
        quick_sort(arr, low, p);
        quick_sort(arr, p + 1, high);
    }
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    arr[size] = 2147483647; 
    size++; 

    quick_sort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}