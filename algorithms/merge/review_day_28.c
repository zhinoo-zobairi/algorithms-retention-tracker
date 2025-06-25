/**
 * Review Day 28 for Merge
 * Created on 2025-06-25
 *
 * This is your review exercise for Merge.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Merge
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void merge(int items[], int size) {
    /* Your implementation here */
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    merge(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
