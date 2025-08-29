/**
 * Review Day 28 for Queue
 * Created on 2025-07-27
 *
 * This is your review exercise for Queue.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Queue
 * TODO: Implement the algorithm from memory to reinforce your learning
 */

// ==================== NORMAL QUEUE ====================

struct Queue
{
    int* head;
    int* tail;
    int* items;
    int capacity;
    int count;
};
// Struct owns the storage, the queue is “one-pass only”; once tail reaches the end, it’s done
void initQueue(struct Queue* q, int capacity){
    q->items = (malloc(sizeof(int) * capacity));    // q->items points to the first element of the allocated array (&items[0])
    if (!q->items) {    // OOM check
        q->capacity = 0;
        q->head = NULL;
        q->tail = NULL;
        q->count = 0;
        return;
    }
    q->capacity = capacity;
    q->head = q->items;           // front = beginning of buffer
    q->tail = q->items;      // next insertion also at beginning
    q->count = 0; 
}

int enqueue(int item, struct Queue* q){
    if (q->capacity == q->count) return -1;
    *(q->tail) = item;
    q->tail ++;     // pointer arithmetic is always in units of the pointed type, not in raw bytes; So, q->tail++ means “move forward by 1 int.”
    q->count ++;
    return 0;
}

int dequeue(struct Queue* q){
    if (q->tail == q->head)
    {
        printf("Queue is empty");
        return -1;
    }
    int element = *(q->head);
    q->head ++;
    q->count --;
    return element;
}

void display(struct Queue* q){
    if (q->head == q->tail) {printf("Queue is empty\n");return;}; // Queue empty
    int* ptr = q->head;
    while (ptr != q->tail)
    {
        printf("%d \n", *ptr);
        ptr ++;
    }
}

// ==================== CIRCULAR QUEUE ====================
struct Node {
    int data;
    struct Node* next;
};
struct LinkedQueue {
    struct Node* head;
    struct Node* tail;
};

void createLinked(struct LinkedQueue* queue) {
    queue->head = queue->tail = NULL;
}

void enqueueLinked(struct LinkedQueue* q, int value){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    if (q->head == q->tail == NULL)
    {
        q->head = q->tail = new_node;
    } else
    {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int dequeueLinked(struct LinkedQueue* q){
    if (q->head == NULL) {
        printf("Queue underflow\n");
        return -1;  
    }
    struct Node* previous = q->head;
    int element = q->head->data;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;  // if queue became empty (because there were only one node inside the queue), reset rear too
    }
    free(previous);
    return element;
}

void displayLinked(struct LinkedQueue* q){
    if (q->head == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node* current = q->head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    } 
}


int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    queue(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
