/**
 * Review Day 1 for Hashing Linear and Quadratic Probing
 * Created on 2025-06-29
 *
 * This is your review exercise for Hashing Linear and Quadratic Probing.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Hashing Linear and Quadratic Probing
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
struct HashTable{
    int size;
    int* table;
};

struct HashTable* create_hash_table(int size) {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    ht->size = size;
    ht->table = (int*)calloc(size, sizeof(int)); // Allocate and initialize to 0
    return ht;
}

int linear_probing(struct HashTable* ht, int index) {
    for (int i = 0; i < ht->size; i++) {
        int probe_index = (index + i) % ht->size;
        if (ht->table[probe_index] == 0) {
            return probe_index;
        }
    }
    return -1; // Table is full
}

int quadratic_probing(struct HashTable* ht, int index) {
    for (int i = 0; i < ht->size; i++) {
        int probe_index = (index + i * i) % ht->size;
        if (ht->table[probe_index] == 0) {
            return probe_index;
        }
    }
    return -1; // Table is full
}

int insert_linear(struct HashTable* ht, int key) {
    int index = key % ht->size;
    
    if (ht->table[index] == 0) {
        ht->table[index] = key;
        return 1;
    } else {
        int probe_index = linear_probing(ht, index);
        if (probe_index != -1) {
            ht->table[probe_index] = key;
            return 1;
        } else {
            printf("Hash table is full (linear)\n");
            return 0;
        }
    }
}

int insert_quadratic(struct HashTable* ht, int key) {
    int index = key % ht->size;
    
    if (ht->table[index] == 0) {
        ht->table[index] = key;
        return 1;
    } else {
        int probe_index = quadratic_probing(ht, index);
        if (probe_index != -1) {
            ht->table[probe_index] = key;
            return 1;
        } else {
            printf("Hash table is full (quadratic)\n");
            return 0;
        }
    }
}

void display(struct HashTable* ht) {
    printf("Hash table: [");
    for (int i = 0; i < ht->size; i++) {
        if (i > 0) printf(", ");
        printf("%d", ht->table[i]);
    }
    printf("]\n");
}

void destroy_hash_table(struct HashTable* ht) {
    free(ht->table);
    free(ht);
}

int main() {
    struct HashTable* ht = create_hash_table(8);
    
    insert_linear(ht, 10);
    insert_linear(ht, 17);
    insert_linear(ht, 27);
    display(ht);
    
    destroy_hash_table(ht);
    return 0;
}

