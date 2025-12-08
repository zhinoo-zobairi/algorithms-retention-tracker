/**
 * Review Day 224 for Recursive List Reversal
 * Created on 2025-12-07
 *
 * This is your review exercise for Recursive List Reversal.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Recursive List Reversal
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp
}
void recursive_list_reversal(int items[], int i, int j) {
if(i >= j){
    return
    }
else{
    swap(&i, &j)
    recursive_list_reversal(int items[], i+1, j-1)
    }
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    recursive_list_reversal(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
