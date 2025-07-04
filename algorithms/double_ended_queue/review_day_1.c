/**
 * Review Day 1 for Double-Ended Queue
 * Created on 2025-07-02
 *
 * This is your review exercise for Double-Ended Queue.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Double-Ended Queue
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct DoubleEndedQueue{
    struct Node* front;
    struct Node* rear;
    int size; // ← current number of elements
}
struct DoubleEndedQueue* createDeque() {
    struct DoubleEndedQueue* deq = (struct DoubleEndedQueue*)malloc(sizeof(struct DoubleEndedQueue));
    deq->front = NULL;
    deq->rear = NULL;
    deq->size = 0;
    return deq;
}
// every time I want to insert a value, I’ll need to create a new node with that value; hence:
struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->data = data;
}

void add_front(struct DoubleEndedQueue* deq, int data) {
    struct Node* new_node = createNode(data);
    if (deq->size == 0) {
        deq->front =deq->rear = new_node;
    }else{
    new_node->next = deq->front;
    deq->front->prev = new_node;
    new_node = deq->front;
    }
    deq->size++;  // track number of elements
}

void add_rear(struct DoubleEndedQueue* deq, int data) {
   struct Node* new_node = createNode(data);
    if (deq->size == 0) {
        deq->front =deq->rear = new_node;
    }else{
        deq->rear->next = new_node;
        new_node->prev = deq->rear;
        deq->rear = new_node;
    } 
    deq->size++;
}

void remove_front(struct DoubleEndedQueue* deq){
    if(deq->front == NULL && deq->rear == NULL){
        printf("No node to remove\n");
        return; // to avoid segmentation fault
    }
    if (deq->front == deq->rear) {
        free(deq->front);
        deq->front = deq->rear = NULL;
    } else {
        struct Node* old_front = deq->front;
        deq->front = old_front->next;
        deq->front->prev = NULL;
        free(old_front);
    }
    deq->size--;
}

void remove_rear(struct DoubleEndedQueue* deq){
    if(deq->front == NULL && deq->rear == NULL){
        printf("No node to remove\n");
        return; 
    }
    if (deq->front == deq->rear) {
        free(deq->rear);
        deq->front = deq->rear = NULL;
    } else {
        struct Node* old_rear = deq->rear;
        deq->rear = old_rear->prev;
        deq->rear->next = NULL;
        free(old_rear);
    }
    deq->size--;
}

void display_dequeue(struct DoubleEndedQueue* deq){
    if(deq->front == NULL && deq->rear == NULL){
        printf("No node to remove\n");
        return; 
    }
    else{
        struct Node* current_deq = deq->front;
        while (current_deq != NULL){
        printf("%d",current_deq->data);
        current_deq = current_deq->next;
        }
        printf("\n");
    }
}

void display_dequeue_reverse(struct DoubleEndedQueue* deq) {
   if(deq->front == NULL && deq->rear == NULL){
        printf("No node to remove\n");
        return; 
    }
    else{
        current_deq = deq->rear;
         while (current_deq != NULL){
        printf("%d",current_deq->data);
        current_deq = current_deq->prev;
        }
        printf("\n");
    }     
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    double-ended_queue(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
