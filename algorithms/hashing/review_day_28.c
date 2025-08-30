/**
 * Review Day 28 for Hashing
 * Created on 2025-07-18
 *
 * This is your review exercise for Hashing.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Hashing
 * TODO: Implement the algorithm from memory to reinforce your learning
 */

struct Node{
    int key;
    struct Node* next;
};

struct HashTable{
    int capacity;
    struct Node** buffer;  // a pointer to the first element of that array
};
/*
struct Node* = one pointer to one linked list head.
struct Node** = one pointer to the first element of an array where each element is a struct Node*.
	•	You need struct Node** buffer; because each slot is a struct Node* (head of a linked list).
	•	Since the number of slots (capacity) is not known at compile time, you don’t write struct Node* buffer[10];.
	•	Instead, you use a pointer (struct Node**) and then dynamically allocate with malloc or calloc at runtime.
*/
void initialiseHT(struct HashTable* ht, int capacity){
    ht->capacity = capacity;
    // ht->buffer = malloc(sizeof(struct Node*) * capacity);
    ht->buffer = calloc(capacity, sizeof(struct Node*));    // calloc ensures they all start as NULL, not garbage values
}

int hashFunction(int key, struct HashTable* ht){
    return key % ht->capacity;
}


void hashing_at_head(struct HashTable* ht, int key) {
    int index = hashFunction(key, ht);
    struct Node* new_node = malloc(sizeof(struct Node));
    if (ht->buffer[index] == NULL){     // ← this moves index * sizeof(struct Node*) bytes forward, then reads the pointer stored in the index-th slot of the hash table.
        new_node->key = key;
        new_node->next = NULL;
        ht->buffer[index] = new_node;
        return;
    }
     new_node->key = key;
     new_node->next = ht->buffer[index];
     ht->buffer[index] = new_node;      // always hook into head
}

void hashing_at_tail(struct HashTable* ht, int key) {
    int index = hashFunction(key, ht);
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->key = key;
    new_node->next = NULL;
    if (ht->buffer[index] == NULL){
        ht->buffer[index] = new_node;
        return;
    }
    struct Node* temp = ht->buffer[index];
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

int search(struct HashTable* ht, int key){
    int index = hashFunction(key, ht);
    if (ht->buffer[index] == NULL)
    {
        return -1;
    }
    struct Node* temp_ptr = ht->buffer[index];
    while (temp_ptr != NULL)
    {
        if (temp_ptr->key == key)
        {
            return 1;
        }
        temp_ptr = temp_ptr->next;
    }
    return -1;
}

int main() {
    struct HashTable* ht = malloc(sizeof(struct HashTable));
    initialiseHT(ht, 10);
    hashing_at_head(ht, 15);
    int result = search(ht, 11);
    printf("Search result: %d\n", result);
    return 0;
}
