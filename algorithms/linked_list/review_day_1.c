/**
 * Review Day 1 for Linked List
 * Created on 2025-06-12
 *
 * This is your review exercise for Linked List.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Linked List
 * TODO: Implement the algorithm from memory to reinforce your learning
 */

struct Node {
    int value;
    struct Node* p; // whatever the pointer points out to decides what the type of the pointer is. If it points to an int, then it should be int*, if it points to a specific type of structure, the pointer will be accordingly from that type!
};

// ‼️ struct Node n1; If you want a persistent linked lists that outlives the function in which it's created, grows, shrinks, and lives across functions, you need to allocate it on the heap using malloc(). That memory persists until you free it.
// You can for sure make an instance globally, and it will be stored it in the global/static data segment, available to any function in the file BUT they're only fine for quick tests
/*
If we do it in stack, as you see we are literally hand-wiring nodes together in stack memory. Each one must be declared in advance.
struct Node *ptr;

struct Node n1, n2, n3; // This is fine globally, the rest should be wrapped inside a main

int main() {
n1.value = 10;
ptr = &n1;
n1.p = &n2;

n2.value = 20;
n2.p = &n3;

n3.value = 30;
n3.p = NULL;

while (ptr != NULL) {
    printf("%d\n", ptr->value); // shorthand for: (*ptr).p -> dereference = the actual Node struct at that address -> the p field inside that struct
    ptr = ptr->p;
};
}
*/

int main() {
    
    // Method 1: Manual Creation with malloc
    printf("Method 1: Manual Creation\n");
    
    struct Node *ptr;
    struct Node *n1 = (struct Node*)malloc(sizeof(struct Node)); // n2 is a pointer to a node. malloc(...) returns a pointer, which we store directly.
    ptr = n1;
    n1->value = 19; 
    struct Node *n2 = (struct Node*)malloc(sizeof(struct Node));
    n1->p = n2; // n2 is a pointer to a node. It is already the address! Cuz malloc(...) returns a pointer, which we store directly.
    n2->value = 39; 
    struct Node *n3 = (struct Node*)malloc(sizeof(struct Node));
    n2->p = n3;
    n3->p = NULL;
    n3->value = 29; 

    while (ptr != NULL) {
        printf("%d\n", ptr->value);
        ptr = ptr->p;
    }

    struct Node* n = n1;

    /*
    You're tasked with burning down a chain of houses.
    But you only have the address of the first house.
    Each house contains a the address of the next house somewhere hidden in it.
    If you:
    •	Burn a house before writing the address of the next house? → You've lost the trail. You're stuck. 
    •	Find the next address, write it down, then burn the house? → You can continue.
    */

    // Free the memory:
    while (n != NULL) { 
        struct Node* next = n->p;  // Read the next house's address first and write it down somewhere
        free(n);                   // Then burn down the current house. n is just a pointer variable: a slot on the stack that stores an address. When I call free(n), I invalidate the memory that n was pointing to, but I do not invalidate the pointer variable itself.
        n = next;                  // Move to the next house by updating your navigator and entering the address I wrote down. It would be Illegal to: n->p after free(n)
    }

    // Method 2: Loop Creation
    printf("\nMethod 2: Loop Creation\n");
    
    int count = 3;
    struct Node* head = NULL; // The government gives you a clipboard (the head pointer) and says: 'once you build the first house, write its address here.'
    struct Node* prev = NULL;

    for (int i = 0; i < count; i++) {
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->value = i * 10;
        new_node->p = NULL;

        if (i == 0) {
            head = new_node;     // For the First house → Builder gives its address to the government. Because head is just a pointer to the first node, we don't say head->p = ... because we're not updating a field inside a house
        } else {
            prev->p = new_node;  // All other houses → clipboard link from previous
        }

        prev = new_node;         // Move clipboard to current house
    }

    // Print loop-created list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->p;
    }

    // Free loop-created list
    current = head;
    while (current != NULL) {
        struct Node* next = current->p;
        free(current);
        current = next;
    }

    return 0;
}
