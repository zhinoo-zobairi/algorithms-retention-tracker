/**
 * Review Day 224 for Hashing Linear and Quadratic Probing
 * Created on 2026-02-07
 *
 * This is your review exercise for Hashing Linear and Quadratic Probing.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Hashing Linear and Quadratic Probing
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void hashing_linear_and_quadratic_probing(int items[], int size) {
    /* Your implementation here */
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    hashing_linear_and_quadratic_probing(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
