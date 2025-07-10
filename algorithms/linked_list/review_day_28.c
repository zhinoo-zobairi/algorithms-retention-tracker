/**
 * Review Day 28 for Linked List
 * Created on 2025-07-09
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
struct Node{
    int value;
    struct Node* next;
};
struct LinkedList{
    struct Node* head;
};

// O(1):
void head_creation(int array[], struct Node** head, int size){ // head → struct Node** → address of the head pointer in main.
    for (int i = 0; i < size; i++)
    {
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->value = array[i];
        new_node->next = *head;
        *head = new_node;   
    }
    //We dereference *head because head is a pointer to the pointer. By dereferencing, we go to the address that head holds, which is the address of the caller’s head, and modify the value stored there, meaning we update the actual head pointer in the caller, not just a local copy inside the function.

}  
        
void tail_creation(int array[], struct Node** head, int size){
    if (*head == NULL)
    {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->value = array[0];
        new_node->next = NULL;
        *head = new_node;
    }
    
    for (int i = 1; i < size; i++)
    {
        struct Node* current = *head;
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->value = array[i];
        new_node->next = NULL;
    }
}

void insert(struct LinkedList* list, int value) {
    if (list->head == NULL)
    {  
    list->head = malloc(sizeof(struct Node));
    list->head->value = value;
    list->head->next = NULL;
    } else
    {
        struct Node* current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = malloc(sizeof(struct Node));
        current->next->value = value;
        current->next->next = NULL;
    }
}

void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

/*
In the first variant, it’s like passing the address of x when we want to change its value — except here, we’re passing the address of the pointer (&head) because we want to modify the pointer itself, not just what it points to. That’s why we use a double star (Node**): it’s a pointer to a pointer we want to update.

In the second variant, we pass the pointer to a LinkedList struct. Since we already have that pointer, we can use arrow notation (->) to directly access and modify its members, like head. There’s no need to pass a pointer to a pointer here, because we’re not trying to replace the list pointer itself, just its contents.
*/
int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    // Test head_creation
    printf("Testing head_creation:\n");
    struct Node* head1 = NULL;
    head_creation(data, &head1, size);
    print_list(head1); // Expected output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

    // Test tail_creation
    printf("\nTesting tail_creation:\n");
    struct Node* head2 = NULL;
    tail_creation(data, &head2, size);
    print_list(head2); // Expected output: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    // Test insert
    printf("\nTesting insert:\n");
    struct LinkedList list;
    list.head = NULL;
    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    print_list(list.head); // Expected output: 10 -> 20 -> 30 -> NULL

    return 0;
}

