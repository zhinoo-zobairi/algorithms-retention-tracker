/**
 * Review Day 28 for Binary Heap Insert Operation
 * Created on 2025-06-02
 *
 * This is your review exercise for Binary Heap Insert Operation.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Binary Heap Insert Operation
 * TODO: Implement the algorithm from memory to reinforce your learning
 * This version is different with day 3, where your get a list where the new element is already inserted and you have to only restore heap hierarchy.
 */
void binary_heap_insert_operation(int items[], int *size, int new_item) {
    int i = *size;
    int inserted_value = new_item;
    while (i > 0 && items[(i - 1) / 2] < inserted_value)
    {
        items[i] = items[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    items[i] = inserted_value;
    (*size)++;
}

int main() {
    int test_data[100] = {9, 5, 6, 1, 2, 3};  // A valid max-heap
    int size = 6;
    
    binary_heap_insert_operation(test_data, &size, 10);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
