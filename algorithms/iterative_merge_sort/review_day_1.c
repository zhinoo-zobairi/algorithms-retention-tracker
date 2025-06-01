/**
 * Review Day 1 for Iterative Merge Sort
 * Created on 2025-05-31
 *
 * This is your review exercise for Iterative Merge Sort.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

#include "../merge/merge.h"

/**
 * Implementation of Iterative Merge Sort
 * TODO: Implement the algorithm from memory to reinforce your learning
 * I need 2 for loops: once for each size: I am basically saying at each size, you have to do a series of actions
 * A second loop for that series of actions I just mentioned: Compute the start, mid and end => prepare it for merge Algorithm) as long as the start is less than the length.
 */
void iterative_merge_sort(int items[], int length) {
    for (int size = 1; size < length; size *= 2)
    {
       for (int start = 0; start < length; start += 2 * size) // I let 'start' hit risky values like 'start' = 'length'-1, but I catch invalid ranges by clamping with min(...) in the next step. We say start += 2 * size, because the next start must jump past: 1. The 'size' elements from the left half, 2. The 'size' elements from the right half.
       {
       int mid = MIN(start + size - 1, length - 1);
       int end = MIN(start + 2 * size - 1, length - 1);

        if (mid < end) {
            merge(items, start, mid, end);
        }
       }
       
    }
   
    
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int length = sizeof(test_data) / sizeof(test_data[0]);
    
    iterative_merge_sort(test_data, length);
    
    printf("Result: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
