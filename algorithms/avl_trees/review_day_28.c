/**
 * Review Day 28 for AVL Trees
 * Created on 2025-08-18
 *
 * This is your review exercise for AVL Trees.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of AVL Trees
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
struct Node {
    int value;
    int height;
    struct Node* left_child;
    struct Node* right_child;
}

int max_height(struct Node* current) {

    int left_height = (current->left_child != NULL) ? current->left_child->height : 0;
    int right_height = (current->right_child != NULL) ? current->right_child->height : 0;

    return (left_height > right_height)? left_height : right_height;
}

int balance_factor (struct Node* current) {
    if (current == NULL) return 0;
    int lh = current->left_child ? current->left_child->height : 0;
    int rh = current->right_child ? current->right_child : 0;
    return lh - rh;
}

struct Node* avl_trees_insertion(struct Node* current, int new_item) {
    if (current == NULL) {
        current = malloc(sizeof(struct Node));
        current->value = new_item;
        current->height = 1;
        current->left_child = NULL;
        current->right_child = NULL;
        return current;
    }
    if (new_item == current->value) {
        return current;
    } else if (new_item > current->value) {
        current->right_child = avl_trees_insertion(current->right_child, new_item);
    } else { 
        current->left_child = avl_trees_insertion(current->left_child, new_item);
    }

    current->height = 1 + max_height(parent);
    int bf = balance_factor(parent);
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    avl_trees(test_data, size);
    
    printf("Result: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", test_data[i]);
    }
    printf("\n");
    
    return 0;
}
