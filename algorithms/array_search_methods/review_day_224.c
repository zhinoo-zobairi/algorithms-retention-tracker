/**
 * Review Day 224 for Array Search Methods
 * Created on 2026-02-28
 *
 * This is your review exercise for Array Search Methods.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Array Search Methods
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void array_search_methods(int items[], int size) {
    /* Your implementation here */
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    array_search_methods(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
