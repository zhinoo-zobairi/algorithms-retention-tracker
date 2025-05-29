/**
 * Review Day 28 for Recursive List Reversal
 * Created on 2025-05-25
 *
 * This is your review exercise for Recursive List Reversal.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @items: The input array of integers. In C, writing `int items[]` is just
 *         syntactic sugar for `int* items`. Both forms mean the function receives
 *         a pointer to the first element of an integer array.
 *
 *         Be careful: writing `int* items[]` is NOT the same: that would mean
 *         an array of int pointers (int*[]), not an array of integers.
 *
 * @size:  The number of elements in the input array.
 *
 * Return: A pointer to a newly heap-allocated array of integers, containing
 *         the reversed values.
 *
 *            Returns a pointer to the first element of the new array.
 *            Whenever we create a function in C that is supposed to return an array,
 *            we must write its return type as a pointer to the array’s element type
 *            (e.g., int*), because C does not allow returning arrays directly.
 */

void recursive_reverser(int reversed_array[], int items[], int length, int write_index){
    if (length <= 0)
    {
    return; // function declared as void, so we can’t return anything
    }
    reversed_array[write_index] = items[length-1];
    recursive_reverser(reversed_array, items, length-1, write_index + 1);

}

int* list_reversal(int items[], int size) { 
    // Allocate memory on the heap for a new array of integers.
    //
    // malloc(...) returns a void* — a generic pointer to a block of raw memory
    // with no associated type. Since we plan to store integers and access them
    // like an array (e.g., reversed[i]), we must assign it to an int* so the
    // compiler treats this memory as a block of ints.
    //
    // Example:
    //   int* reversed = malloc(size * sizeof(int));   // block of ints
    //   char* str = malloc(length + 1);               // block of chars for a string
    //   float* values = malloc(n * sizeof(float));    // block of floats
    //
    // Always multiply by sizeof(type) to ensure correct byte count across platforms
    int* reversed_array = malloc(size * sizeof(int));
    recursive_reverser(reversed_array, items, size, 0);
    return reversed_array;

}

int main() {

    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    int* reversed = list_reversal(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", reversed[i]);
    }
    printf("\n");

    free(reversed); // Free heap memory
    
    return 0;
}
