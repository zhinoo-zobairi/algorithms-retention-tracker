/**
 * Review Day 224 for Counting Sort
 * Created on 2026-01-18
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
int max_finder(int items[], int size){
    int max = items[0];
    for (int i = 1; i < size; i++)
    {
        if (items[i] > max)
        {
            max = items[i];
        }
    }
    return max;
}

void counting_sort(int items[], int size) {
    int max = max_finder(items, size);
    int counter[max+1] = {0};
    for (int i = 0; i < size; i++)
    {
        counter[items[i]]++;
    }
    int k = 0;
    for (int i = 0; i < max+1; i++)
    {
        while (counter[i] != 0)
        {
            items[k] = i;
            counter[i]--;
            k++;
        }
    }
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
