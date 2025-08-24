/**
 * Review Day 28 for Binary Search Tree
 * Created on 2025-08-16
 *
 * This is your review exercise for Binary Search Tree.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Binary Search Tree
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void binary_search_tree(int items[], int size) {
    /* Your implementation here */
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    binary_search_tree(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
