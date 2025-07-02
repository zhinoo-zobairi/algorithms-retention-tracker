/**
 * Review Day 1 for Double-Ended Queue
 * Created on 2025-07-02
 *
 * This is your review exercise for Double-Ended Queue.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Double-Ended Queue
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void double-ended_queue(int items[], int size) {
    /* Your implementation here */
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    double-ended_queue(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
