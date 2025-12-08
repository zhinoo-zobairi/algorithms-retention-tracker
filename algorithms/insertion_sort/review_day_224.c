/**
 * Review Day 224 for Insertion Sort
 * Created on 2025-12-06
 *
 * This is your review exercise for Insertion Sort.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Insertion Sort
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void insertion_sort(int items[], int size) {
    for (int i = 1; i < size; i++){ // the left side of && is evaluated first, so when j becomes -1, this tries to evaluate items[j] before checking j >= 0. That is out-of-bounds access and undefined behavior.
        int key = items[i];
        int j = i - 1;
        while (j >= 0 && key < items[j]){
            items[j+1] = items[j];
            j--;
        }
        items[j+1] = key
    }
}
int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    insertion_sort(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
