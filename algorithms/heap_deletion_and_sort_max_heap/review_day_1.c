/**
 * Review Day 1 for Heap Deletion and Sort Max Heap
 * Created on 2025-05-12
 *
 * This is your review exercise for Heap Deletion and Sort Max Heap.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Heap Deletion and Sort Max Heap
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
#define MAX_SIZE 100
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heap_deletion_and_sort_max_heap(int items[], int size) {
    int deleted_elements[MAX_SIZE];
    int deleted_count = 0;
    int items_length = size - 1;
    while (items_length > 0)
    {
       int deleted_item = items[1];
       items[1] = items[items_length];
       items_length --;

       deleted_elements[deleted_count] = deleted_item;
       deleted_count++;
        
       int i = 1;
       
       while (2*i <= items_length)
       {
        int left = 2*i;
        if (2*i + 1 <= items_length)
        {
            int right = 2*i +1;

            if (items[left] > items[right] && items[left] > items[i])
            {
                swap (&items[left], &items[i]);
                i = left;
            }
            else if (items[right] > items[i]) {
            swap(&items[right], &items[i]);
            i = right;
            } else 
            {
            break;
            }
            
            
        }
        else
        {
            if (items[left]>items[i])
            {
                swap (&items[left], &items[i]);
            }
            else
            {
                break;
            }
            
            
        }
        
       }

    }
    printf("Sorted (descending): ");
    for (int i = 0; i < deleted_count; i++) {
        printf("%d ", deleted_elements[i]);
    }
    printf("\n");
}

int main() {
    int test_data[] = {0, 9, 5, 6, 1, 2, 5}; // dummy at index 0
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    heap_deletion_and_sort_max_heap(test_data, size);
    
    return 0;
}
