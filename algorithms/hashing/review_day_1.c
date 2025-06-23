/**
 * Review Day 1 for Hashing
 * Created on 2025-06-21
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
struct Node
{
    struct Node* next;
    int value;
};


// Heads[index] is itself a pointer and we pass its address to the insert function because we want to go to that address and change the content of it:
// Heads[index] is of type struct Node*
// &Heads[index] is of type struct Node**
// Version A - Gets &Heads[index] and value, and updates that one chain = Caller owns the head, passes it to insert, and Head should already be pointing to the correct bucket:
// use void insert(struct Node* Heads[], int value, int mode) when the function is responsible for the entire hash table, not just a single bucket, but below we modify one bucket:

void insert(struct Node** Head, int value, int mode) {
    if (mode == 0) { // insert at head
        struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
        n1->value = value;
        n1->next = *Head;
        *Head = n1;
 
    }else { // insert at tail
        struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
        n1->value = value;
        n1->next = NULL;

        if (*Head == NULL) { // what if *Head == NULL? Prev_node is NULL → Prev_node->next is illegal → segfault
            *Head = n1;
        } else {
            struct Node* Prev_node = *Head;
            while (Prev_node->next != NULL) {
                Prev_node = Prev_node->next;
            }
            Prev_node->next = n1;
    }
}
}

int hash_function(int key){
    return key % 10;
}
// For bulk insert and local ownership. Owns the hash table (e.g., Heads[10]) and calls insert() When you don’t need to iterate the bucket contents in a meaningful order — insert-at-head is king.
void hashing_head(int items[], int size){
    struct Node* heads_of_table[10] = {NULL};
    for (int i = 0; i < size; i++)
    {
        int index = hash_function(items[i]);
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->next = heads_of_table[index];
        new_node->value = items[i];
        heads_of_table[index] = new_node;
    }
}

/*
When performing tail insertion during hashing, we loop through each input value.
For each value:
- We compute its hash index to find the correct bucket
- Then we check if that bucket (i.e., Heads[index]) is empty:
- ✅ If yes → this is the first value in the chain → create a node and assign it directly to Heads[index]
- ✅ If no → traverse the linked list until the last node (where node->next == NULL), and then attach the new node at the end.
*/

void hashing_tail(int items[], int size){
    struct Node* heads_of_table[10] = {NULL};
     for (int i = 0; i < size; i++)
    {
        int index = hash_function(items[i]);
        if (heads_of_table[index] == NULL)
        {
            struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node)));
            heads_of_table[index] = new_node;
            new_node->next = NULL;
            new_node->value = items[i];
        } else{
        struct Node* temp_node = heads_of_table[index];
        while (temp_node->next != NULL)
        {
        temp_node = temp_node->next;
        }
        struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node))); // allocated new memory for the node-I need a new node; the current memory has no space for it.
        temp_node->next = new_node; // correctly connected the last node to the new node 
        new_node->next = NULL; // terminated the list 
        new_node->value = items[i]; // assigned the correct value
            }
    }
}

void print_table(struct Node* Heads[], int size){ // passing a hash table — an array of head pointers — one per bucket
    for (int i = 0; i < size; i++)
    {
        printf("Bucket %d: ", i); // We’re not creating a new node; we’re just assigning the pointer to the start of an existing linked list 
        struct Node* node = Heads[i];
        while (node != NULL)
        {
            printf("%d -> ", node->value);
            node = node->next;
        }
        printf("NULL\n");
        
    }
    
}


int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    hashing_tail(test_data, size);
    hashing_head(test_data, size);
    struct Node* new[10] = {NULL};

    insert(&new[1], 10, 1); // explicitly inserting 10 into bucket 1

    print_table(new, 10);    
    return 0;
}
