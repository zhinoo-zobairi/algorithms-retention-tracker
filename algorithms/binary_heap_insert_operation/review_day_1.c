/**
 * Review Day 1 for Binary Heap Insert Operation
 * Created on 2025-05-06
 *
 * This is your review exercise for Binary Heap Insert Operation.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Binary Heap Insert Operation
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void binary_heap_insert_operation(int items[], int n) {
    int new_item = items[n];
    int i=n-1;
   while (i>0 && new_item>items[i/2])
   {
    items[i] = items[i/2];
    i = i/2;
   }
   items[i] = new_item;
   
}

int main() {
    int test_data[] = {-1, 9, 5, 5, 2, 1, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    binary_heap_insert_operation(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
