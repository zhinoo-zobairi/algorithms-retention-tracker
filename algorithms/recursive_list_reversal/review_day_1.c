/**
 * Review Day 1 for Recursive List Reversal
 * Created on 2025-04-28
 *
 * This is your review exercise for Recursive List Reversal.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Recursive List Reversal
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void swap(int *a, int *b) { // We are stating that we expect pointers, not values. Because in C, if we want to actually change two elements inside an array, we must pass their addresses (pointers). We don't want to only swap local copies. We want to directly modify the array elements in memory.
    int temp = *a; // We dereference the pointers when received; So, temp can receive the value inside the pointer a.
    *a = *b;
    *b = temp;
}

void recursive_list_reversal(int items[], int left, int right) {
    if (left >= right) { // In odd-sized arrays, left == right exactly in the middle. But when size is evem they never exactly equal, hence the >!
        return;
    }
    
    swap(&items[left], &items[right]);
    recursive_list_reversal(items, left + 1, right - 1);
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    recursive_list_reversal(test_data, 0, size-1);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}

