/**
 * Review Day 1 for Counting Sort
 * Created on 2025-06-09
 *
 * This is your review exercise for Counting Sort.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Counting Sort
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
int find_max(int items[], int size){
    int largest = items[0];

    for (int i = 0; i < size; i++)
    {
        if (items[i] > largest)
        {
            largest = items[i];
        }
    }
    return largest;
}

void counting_sort(int items[], int size) {

    int largest = find_max(items, size);

    int *aux = (int*)malloc((largest+1)*sizeof(int)); //  This way, we get slots for index 0 all the way up to largest, no buffer overrun, no segfaults, no memory stomping chaos.
    
    for (int i = 0; i < largest + 1; i++)
    {
        aux[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        aux[items[i]] += 1;
    }
    
    int i = 0;
    int k = 0;

    for (int i = 0; i <= largest; i++) { // For each i, while aux[i] > 0, write i into items[k], then increment k, decrement aux[i]
        while (aux[i] > 0) {
            items[k++] = i;
            aux[i]--;
        }
    }
    free(aux);
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    counting_sort(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
