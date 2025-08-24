/**
 * Review Day 28 for Array Operations
 * Created on 2025-07-18
 *
 * This is your review exercise for Array Operations.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Array Operations
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
struct Array{
    int *arr; // a pointer to the first element of a contiguous block of ints in memory
    int size; // used slots
    int capacity; // allocated slots
};

// Both the struct and the buffer are on the heap. Caller only has a struct Array*. 
void initArray(struct Array **array, int cap){
    *array = (struct Array*)malloc(sizeof(struct Array));
    (*array)->size = 0;
    (*array)->capacity = cap;
    (*array)->arr = (int*)malloc(sizeof(int) * cap);
}

void insert(struct Array *array, int new_element){
    if(array->capacity > array->size){
    array->arr[array->size] = new_element;
    array->size = array->size + 1;
    }else
    {
        printf("Array is full!");
    }
}

void insert_at(struct Array *array, size_t index, int new_element){
    if (array == NULL || array->arr == NULL) return;
    if (index > array->size) return;
    if (array->size == array->capacity) return;
    if (array->size < array->capacity)
    {
        for (size_t i = array->size; i > index ; i--)
        {
            array->arr[i] = array->arr[i - 1];
        }
        array->arr[index]= new_element;
        array->size = array->size + 1;
    }
}

void delete_at(struct Array *array, size_t index) {
    if (array == NULL || array->arr == NULL) {
        printf("Array not initialized\n");
        return;
    }
    if (array->size == 0) {
        printf("Array is empty\n");
        return;
    }
    if (index >= array->size) {
        printf("Index out of bounds\n");
        return;
    }
    for (size_t i = index; i < array->size - 1; i++) { // If index == array->size - 1. The condition of the loop is false immediately.
        array->arr[i] = array->arr[i + 1];
    }
    array->size--;
    array->arr[array->size] = 0;
}

void destroyArray(struct Array **parray) {
    if (parray == NULL || *parray == NULL) return;
    free((*parray)->arr);  // free buffer
    free(*parray);         // free struct
    *parray = NULL;        // also nulls caller’s pointer
}

int main() {
    struct Array *a;
    initArray(&a, 10);
    if (a == NULL) return 1;
    insert(a, 5);
    insert(a, 20);
    delete_at(a, 1);
    destroyArray(&a);
    return 0;
}
