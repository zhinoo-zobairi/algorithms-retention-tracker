/**
 * Review Day 1 for Queue
 * Created on 2025-06-30
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
struct Queue{
    int rear;
    int front; // front and rear represent array indices, not addresses
    int *array;
    int size;
};
void createQueue(struct Queue* queue, int size){
    queue->size = size;
    queue->array = (int*)malloc(sizeof(int)*queue->size);
    queue->front = queue->rear = -1; 
}

void enqueue(int value, struct Queue* queue){
    if (queue->rear == queue->size -1)
    {
        printf("Queue is full!");
    }else
    {
        queue->rear ++;
        queue->array[queue->rear] = value;
    }    
}

int dequeue(struct Queue* queue){
    if (queue->rear == queue->front)
    {
        printf("Queue is empty!");
        return -1;
    } else
    {
        queue->front++;
        return queue->array[queue->front];
    }
}

void display(struct Queue queue){
    if (queue.front == queue.rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue.front + 1; i <= queue.rear; i++) {
        printf("%d ", queue.array[i]);
    }
    printf("\n");
}
// ==================== CIRCULAR QUEUE ====================
struct CircularQueue {
    int rear;
    int front;
    int *array;
    int size;
};

void createCircular(struct CircularQueue* cq, int size){
    cq->size = size;
    cq->rear = cq->front = 0;
    cq->array = (int*)malloc(sizeof(int)*cq->size);
}

void enqueueCircular(int value, struct CircularQueue* cq){
    if ((cq->rear + 1) % cq->size == cq->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        cq->rear = (cq->rear + 1) % cq->size;
        cq->array[cq->rear] = value;
    } 
}

int dequeueCircular(struct CircularQueue* cq){
    if (cq->rear == cq->front)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        cq->front = (cq->front + 1) % cq->size;
        return cq->array[cq->front];
    }
}

void displayCircular(struct CircularQueue* cq){
    if (cq->rear == cq->front) {
        printf("Queue is empty\n");
        return;
    }
    int i = (cq->front + 1) % cq->size;
    printf("Queue: ");
    do {
        printf("%d ", cq->array[i]);
        i = (i + 1) % cq->size;
    } while (i != (cq->rear + 1) % cq->size);
    printf("\n");
}

// ==================== LINKED LIST QUEUE ====================
struct Node {
    int data;
    struct Node* next;
};

struct LinkedQueue {
    struct Node* front;
    struct Node* rear;
};
void createLinked(struct LinkedQueue* queue) {
    queue->front = queue->rear = NULL;
}
void enqueueLinked(int value, struct LinkedQueue* queue) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeueLinked(struct LinkedQueue* queue) {
    if (queue->front == NULL) {
        printf("Linked Queue is empty!\n");
        return -1;
    } else {
        struct Node* temp = queue->front;
        int value = temp->data;
        queue->front = queue->front->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        free(temp);
        return value;
    }
}

void displayLinked(struct LinkedQueue* lq) {
    if (lq->front == NULL) {
        printf("Linked Queue is empty\n");
        return;
    }
    struct Node* temp = lq->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("=== Queue Implementations Demo ===\n\n");
    
    printf("1. Normal Queue Demo:\n");
    struct Queue q;
    createQueue(&q, 5);
    enqueue(10, &q);
    enqueue(20, &q);
    enqueue(30, &q);
    display(q);
    printf("Dequeued: %d\n", dequeue(&q));
    display(q);
    printf("\n");
    
    printf("2. Circular Queue Demo:\n");
    struct CircularQueue cq;
    createCircular(&cq, 5);
    enqueueCircular(10, &cq);
    enqueueCircular(20, &cq);
    enqueueCircular(30, &cq);
    displayCircular(&cq);
    printf("Dequeued: %d\n", dequeueCircular(&cq));
    displayCircular(&cq);
    enqueueCircular(40, &cq);
    displayCircular(&cq);
    printf("\n");
    
    printf("3. Linked Queue Demo:\n");
    struct LinkedQueue lq;
    createLinked(&lq);
    enqueueLinked(10, &lq);
    enqueueLinked(20, &lq);
    enqueueLinked(30, &lq);
    displayLinked(&lq);
    printf("Dequeued: %d\n", dequeueLinked(&lq));
    displayLinked(&lq);
    
    free(q.array);
    free(cq.array);
    
    return 0;
}