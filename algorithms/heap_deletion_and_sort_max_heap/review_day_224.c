/**
 * Review Day 224 for Heap Deletion and Sort Max Heap
 * Created on 2025-12-21
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
    /* Your implementation here */
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    heap_deletion_and_sort_max_heap(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
