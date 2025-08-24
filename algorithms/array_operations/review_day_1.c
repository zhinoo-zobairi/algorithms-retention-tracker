/**
 * Review Day 1 for Array Operations
 * Created on 2025-06-21
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
struct Array {
    int size;
    int length;
    int *items;
};
// like a constructor in Java/Python, the struct itself is on the stack (e.g., inside main or passed by value). The buffer (items) is on the heap, allocated with malloc. We don’t need a struct Array** because the struct itself is not malloc’d. We just pass struct Array* to initialize the buffer.
void array_operations_create(struct Array *array, int size){
    array->items = (int*)malloc(sizeof(int) * size); 
    array->length = 0;
    array->size = size;
}

void array_operations_push(struct Array *array, int new_value) { 
    if (array->length == array->size)
    {
        printf("Stack Overflow");
    } else {
        array->items[array->length] = new_value;
        array->length ++;
    }
}

int array_operations_pop(struct Array *array){
    if (array->length == 0)
    {
        printf("Stack Underflow");
        return -1;
    } else {
        array->length--;
        return array->items[array->length - 1];
    }
}

void array_operations_delete(struct Array *array, int index){
    if (index >= array->length || index < 0)
    {
        printf("Index not in range");
    }else{
        for (int i = index; i < array->length - 1; i++)
        {
            array->items[i] = array->items[i+1];
        }
        array->length--;
    }
}


int main() {
    struct Array array;
    array_operations_create(&array, 5);
    array_operations_push(&array, 10);
    array_operations_push(&array, 20);

    printf("Result: ");
    for (int i = 0; i < array.length; i++) {
        printf("%d ", array.items[i]); // If items is int *, just use: items[i], only use *items if you want the first item, like: *items == items[0]
    }
    printf("\n");

    array_operations_pop(&array);
    array_operations_push(&array, 50);
    array_operations_delete(&array, 0);
    printf("Result: ");
    for (int i = 0; i < array.length; i++) {
        printf("%d ", array.items[i]); 
    }
    printf("\n");

    return 0;
}
