/**
 * Review Day 28 for Insertion Sort
 * Created on 2025-05-24
 *
 * This is your review exercise for Insertion Sort.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Insertion Sort
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void insertion_sort(int items[], int size) {
    int i, j;
    for (i = 1; i < size; i++)
    {
        int key = items[i];
        j = i - 1;
        for (; j >= 0; j--)
        {
            if (items[j]>key)
            {
               items[j+1] = items[j]; 
            }else
            {
                break;
            }
            
        }
        items[j+1] = key;
    }
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    insertion_sort(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
