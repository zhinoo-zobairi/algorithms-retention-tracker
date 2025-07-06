/**
 * Review Day 28 for Counting Sort
 * Created on 2025-07-06
 *
 * This is your review exercise for Counting Sort.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>


int maximum(int items[], int size) {
    if (size <= 0) {
        return -1; 
    }
    int max = items[0];
    for (int i = 1; i < size; i++) { 
        if (items[i] > max) {
            max = items[i];
        }
    }
    return max;
}


void counting_sort(int items[], int size) {
    int max = maximum(items, size);
    if (max < 0) {
        printf("Error: Negative values are not supported.\n");
        return;
    }

    int aux[max + 1];
    for (int i = 0; i < max + 1; i++) {
        aux[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        if (items[i] < 0) {
            printf("Error: Negative values are not supported.\n");
            return;
        }
        aux[items[i]]++;
    }

    int i = 0;
    for (int j = 0; j < max + 1; j++) {
        while (aux[j] > 0) {
            items[i] = j;
            aux[j]--;
            i++;
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
