/**
 * Review Day 1 for Stack Operations
 * Created on 2025-06-18
 *
 * This is your review exercise for Stack Operations.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Stack Operations
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
struct Stack
    {
        int *array_location;
        int size;
        int top;
    };



// You must manually pass pointers to simulate “method calls.”

void stack_operation_push(struct Stack* stack, int value) {
    if (stack->top == stack->size - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack->top ++;
        stack->array_location[stack->top] = value; // array_location[index] is already syntactic sugar for: *(array_location + index) = Go index steps forward in memory, Dereference automatically, So you can assign or read a value
    }

}

void stack_operation_pop(struct Stack* stack){
    stack->array_location[stack->top] = 0; // NULL is for pointers. Don’t assign it to an int.b v
    stack->top --;
    
}

int stack_operation_peek(struct Stack* stack, int index){
    if (index < 0 || index > stack->top) { // if someone tries to peek into an empty or invalid position
        printf("Invalid index: %d\n", index);
        return -1;
    }
    int data = stack->array_location[index];
    return data;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void stack_operation_reverse(struct Stack* stack){
    int j = stack->top;
    for (int i = 0 ; i < j; i++)
    {
        swap(&stack->array_location[i],&stack->array_location[j]);
        j--;
    }  
}

int stack_operation_search(struct Stack* stack, int value){
    for (int i = 0; i <= stack->top; i++)
    {
        if (stack->array_location[i] == value)
        {
            return i;
        }else
        {
            return -1;
        }
    }
}



int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);

    struct Stack stack;
    stack.size = size;
    stack.top = -1;
    stack.array_location = (int*)malloc(stack.size * sizeof(int));
    
    for (int i = 0; i < size; i++) {
        stack_operation_push(&stack, test_data[i]);
    }

    stack_operation_pop(&stack);

    printf("Stack after popping one element: ");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.array_location[i]);
    }
    printf("\n");

    stack_operation_reverse(&stack);

    printf("Stack after reversing: ");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.array_location[i]);
    }
    printf("\n");

    int search_val = 5;
    int found_index = stack_operation_search(&stack, search_val);
    if (found_index != -1) {
        printf("Value %d found at index %d\n", search_val, found_index);
    } else {
        printf("Value %d not found in stack\n", search_val);
    }

    free(stack.array_location);

    return 0;
}
