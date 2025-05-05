// Review Day 1 for Insertion Sort
// Created on 2025-04-27

/*
This is your review exercise for Insertion Sort.
Complete the implementation below to reinforce your understanding.
*/

#include <stdio.h>

void insertionSort(int arr[], int len) {
    int i;
    for (i = 1; i < len; i++)
    {
        int temp = arr[i]; //Modern C actually prefers variable declarations as close as possible to their use.
        int j = i -1;
        while (arr[j] > temp && j>= 0)
        {
            arr[j+1] = arr[j]; //If you change values in the same function, no pointers needed.
                                //If you want another function to change values, you must give it pointers.
            j--;
        }
      arr[j+1] = temp;  
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]); //	sizeof(arr) → Total memory size of the entire array (e.g., 6 integers × 4 bytes each = 24 bytes)
                                            // 	sizeof(arr[0]) → Size of one element (4 bytes for an int)
    insertionSort(arr, size);               // 	Divide total by one item size = number of elements: 24 bytes / 4 bytes = 6 elements

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}