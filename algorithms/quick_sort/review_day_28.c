/**
 * Review Day 28 for Quick Sort
 * Created on 2025-06-15
 *
 * This is your review exercise for Quick Sort.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Quick Sort
 * TODO: Implement the algorithm from memory to reinforce your learning
 */

 void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
 }

 int partition(int items[], int l, int h){
    int pivot = items[l];
    int i = l + 1;
    int j = h;

    while (i<=j)
    {
        while (i<=j && items[i] <= pivot)
        {
            i++;
        }
        while (i<=j && items[j] >= pivot)
        {
            j--;
        }
        if (i <= j)
        {
            swap(&items[i], &items[j]);
        }
        else
        {
            break;
        }
        
        
    }
    swap(&items[j], &items[l]); // If you swap with pivot, then pivot gets overwritten with items[j] (useless, pivot is a dead local copy!)

    return j;
 }


void quick_sort(int items[], int low, int high) {
    if (low < high) {
        int p = partition(items, low, high);
        quick_sort(items, low, p);
        quick_sort(items, p + 1, high);
    }
}

int main() {
    int arr[] = {9, 3, 7, 1, 8, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}