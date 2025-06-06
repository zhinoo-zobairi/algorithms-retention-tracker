/**
 * Review Day 1 for Merge
 * Created on 2025-05-29
 *
 * This is your review exercise for Merge.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

/**
 * Implementation of Merge
 * TODO: Implement the algorithm from memory to reinforce your learning
 */

void merge(int items[], int l, int mid, int h) {
    int i = l;
    int j = mid +1;
    int k = 0;
    int temp_list[100];
    while (i<=mid && j<=h)
    {
        if (items[i]<= items[j])
        {
            temp_list[k++] = items[i++];
        }
        else
        {
            temp_list[k++] = items[j++];
        }  
    }
    for (; i <= mid; i++, k++)
    {
        temp_list[k] = items[i];
    }
    for (; j <= h; j++, k++)
    {
        temp_list[k] = items[j];
    }

    for (i = l; i<= h; i++)
    {
        items[i]=temp_list[i-l];  
// If you called merge(test_data, 5, 3, 2) (merging from index 2 to 5): When i = 2: items[2] = temp_list[2] ❌ (should be temp_list[0]) --- When i = 3: items[3] = temp_list[3] ❌ (should be temp_list[1])
    }
        
}

int test_main() {
    int test_data[] = {2, 5, 9, 1, 5, 6};  // merge function expects two already sorted subarrays to merge together: Left: [2,5,9] Right: [1,5,6]
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    merge(test_data, 0, 2, 5);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
