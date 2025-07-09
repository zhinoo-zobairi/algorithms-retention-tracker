/**
 * Review Day 1 for Priority Queue
 * Created on 2025-07-02
 *
 * This is your review exercise for Priority Queue.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Priority Queue ARRAY-BASED
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
struct PriorityQueue{
    int *array;
    int size;
    int count;
};

void priority_queue_unsorted_insertion(int data, struct PriorityQueue* pq) {
    if (pq->count == pq->size)
    {
        printf("Queue is full.\n");
        return;
    }
    else
    {
        pq->array[pq->count] = data;
        pq->count++;
    }
}

void priority_queue_sorted_insertion(int data, struct PriorityQueue* pq){
    if (pq->count == pq->size)
    {
        printf("Queue is full.\n");
        return;
    } else
    {
        pq->array[pq->count] = data; // insert at end
        pq->count++; // insert at end
    }
    if (pq->count != 1)
    {
        int j = pq->count - 1;
        while (j > 0 && pq->array[j-1] > data)
        {
            pq->array[j] = pq->array[j - 1];
            j--;
        }
        pq->array[j] = data;
    }    
}

int priority_queue_deletion_constant_time(struct PriorityQueue* pq){
        if (pq->count == 0) {
        printf("Queue is empty.\n");
        return -1;
    }
    int deleted = pq->array[pq->count - 1];
    pq->count --;
    return deleted;
}

int priority_queue_deletion_n_time(struct PriorityQueue* pq){
    if (pq->count == 0) {
        printf("Queue is empty.\n");
        return -1;
    }
    int max = pq->array[0];
    int index = 0;
    for (int i = 1; i < pq->count; i++)
    {
        if (pq->array[i] > max)
        {
            max = pq->array[i];
            index = i;
        }
    }
    pq->array[index] = pq->array[pq->count - 1]; // filling the hole
    pq->count--;
    return max;
}

void display_priority_queue(struct PriorityQueue* pq) {
    if (pq->count == 0) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = 0; i < pq->count; i++) {
        printf("%d ", pq->array[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    pq.size = 10;
    pq.array = (int*)malloc(sizeof(int) * pq.size);
    pq.count = 0;

    printf("Testing Priority Queue:\n");

    // unsorted insertion
    printf("\nUnsorted Insertion:\n");
    priority_queue_unsorted_insertion(30, &pq);
    priority_queue_unsorted_insertion(20, &pq);
    priority_queue_unsorted_insertion(50, &pq);
    priority_queue_unsorted_insertion(40, &pq);
    printf("Queue after unsorted insertion: ");
    display_priority_queue(&pq);

    // deletion (O(n) time)
    printf("\nDeletion (O(n) time):\n");
    int deleted = priority_queue_deletion_n_time(&pq);
    printf("Deleted element: %d\n", deleted);
    printf("Queue after deletion: ");
    display_priority_queue(&pq);

    // sorted insertion
    printf("\nSorted Insertion:\n");
    priority_queue_sorted_insertion(25, &pq);
    priority_queue_sorted_insertion(35, &pq);
    printf("Queue after sorted insertion: ");
    display_priority_queue(&pq);

    // deletion (O(1) time)
    printf("\nDeletion (O(1) time):\n");
    deleted = priority_queue_deletion_constant_time(&pq);
    printf("Deleted element: %d\n", deleted);
    printf("Queue after deletion: ");
    display_priority_queue(&pq);

    free(pq.array);
    return 0;
}
