/**
 * Review Day 28 for Iterative Merge Sort
 * Created on 2025-06-27
 *
 * This is your review exercise for Iterative Merge Sort.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../merge/merge.h"


/**
 * Implementation of Iterative Merge Sort
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
int min(int a, int b) {
    if (a < b)
    {
        return a;
    }
    
    else return b;
}

void iterative_merge_sort(int items[], int size) {
    for (int p = 1; p < size; p *= 2)
    {
        for (int i = 0; i < size; i += 2*p)
        {
            int l = i;
            
            int mid = min(i + p - 1, size - 1);

            int h = min(i + 2 * p - 1, size - 1);

            if (mid < size) merge(items, l, mid, h);
        }
        
    }
    
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    iterative_merge_sort(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
