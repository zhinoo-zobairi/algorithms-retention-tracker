/**
 * Review Day 1 for Iterative Merge Sort
 * Created on 2025-05-31
 *
 * This is your review exercise for Iterative Merge Sort.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Iterative Merge Sort
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void iterative_merge_sort(int items[], int size) {
    /* Your implementation here */
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
