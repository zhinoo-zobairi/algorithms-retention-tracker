/**
 * Review Day 28 for Merge
 * Created on 2025-06-25
 *
 * This is your review exercise for Merge.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Merge
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void merge(int items[], int l, int mid, int h) {
    int size = h - l + 1;
    int i = l; int j = mid + 1;
    int k = 0;
    int *p;
    p = (int*)(malloc(sizeof(int)*size));
    while (i <= mid && j <= h)
    {
        if (items[i] <= items[j])
        {
            p[k++] = items[i++];
        }else{
            p[k++] = items[j++];
        } 
    }
    while (i <= mid)
    {
        p[k++] = items[i++];
    }
     while (j <= h)
    {
        p[k++] = items[j++];
    }
    k = 0;
    for (int i = l; i <= h; i++)
    {
        items[i] = p[k++];
    }
}

int main() {
    int test_data[] = {10, 11, 12, 3, 4, 5};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    merge(test_data, 0, 2, 5);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
