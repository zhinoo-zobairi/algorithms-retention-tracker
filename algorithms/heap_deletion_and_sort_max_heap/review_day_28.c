/**
 * Review Day 28 for Heap Deletion and Sort Max Heap
 * Created on 2025-06-08
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
void heap_deletion_and_sort_max_heap(int items[], int size) {
    int deleted_elements[100];
    int deleted_index = 0;
    while (size > 0)
    {    
    int deleted_element = items[0];
    deleted_elements[deleted_index++] = deleted_element;
    items[0] = items[size - 1];
    size--;
    int i = 0;
    while (2 * i + 1 < size){
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int larger_child = left_child; // I initially made the mistake of having int larger_child = items[left_child] which got me stuck, where I had to assign the index to current i, and I couldn't tell if it was right or left child's index.
        if (right_child < size && items[right_child] > items[left_child]){
            larger_child = right_child;
        }
        if (items[i] < items[larger_child]){
            int temp = items[i];
            items[i] = items[larger_child];
            items[larger_child] = temp;
            i = larger_child;
            }else
            {
                break;
            }
            
        }        
    }
    printf("Sorted array (ascending): ");
    for (int k = deleted_index - 1; k >= 0; k--) {
    printf("%d ", deleted_elements[k]);
}
}

int main() {
    int heap[] = {50, 30, 40, 10, 5, 20, 35};
    int size = sizeof(heap) / sizeof(heap[0]);

    heap_deletion_and_sort_max_heap(heap, size);

    return 0;
}