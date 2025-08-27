/**
 * Review Day 1 for AVL Trees
 * Created on 2025-07-22
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
    struct Node *rchild; // the struct only holds an address to another node, not the full node itself.
    struct Node *lchild; // The compiler cannot compute the memory size of Node because it would need to know the size of lchild, which itself contains another lchild, and so on forever. The size of a pointer is fixed, so the compiler can calculate the size of the struct. In fact, every expression that involves sizeof(struct Node) must be resolvable at compile time, because sizeof is a compile-time operator.
}*root = NULL; // immediately declare a variable of type is struct Node * , identical to writing struct Node *root = NULL;

int maxHeight(struct Node* leftChild, struct Node* rightChild) { // General ternary operator is evaluate_condition ? expression_if_condition_true : expression_if_condition_false
    int leftHeight  = (leftChild  != NULL) ? leftChild->height  : 0;
    int rightHeight = (rightChild != NULL) ? rightChild->height : 0;
    return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}
int balanceFactor(struct Node* n){
    if (n == NULL) return 0;
    int lh = n->lchild ? n->lchild->height : 0; // we save the result in a new variable, so that we do not risk dereferencing a null pointer and we either work with zero or another valid integer
    int rh = n->rchild ? n->rchild->height : 0;
    return lh - rh;
}

struct Node* rotateRight(struct Node* y){
    // Before reassigning pointers, grab(cache) any you’ll need later:
    struct Node* new_root = y->lchild;  // The left child of our root(y) is not gonna remain left child of it. It will get promoted to the new root. So, we cache it.
    struct Node* middle = new_root->rchild;  // This has to be cached, because it won't stay the right child of that node that is becoming the new root anymore. It will be the left child of the former root!
    new_root->rchild = y;  // y (the original parent) is now the right child of new_root
    y->lchild = middle;
    // update the height of lower nodes first, because their height values feed into the height of the upper node:
    y->height = 1 + maxHeight(y->lchild, y->rchild);
    new_root->height = 1 + maxHeight(new_root->lchild, new_root->rchild);
    return new_root;
}
struct Node* rotateLeft(struct Node* y){
    struct Node* new_root = y->rchild;
    struct Node* middle = new_root->lchild;
    y->rchild = middle;
    new_root->lchild = y;
    y->height = 1 + maxHeight(y->lchild, y->rchild);
    new_root->height = 1 + maxHeight(new_root->lchild, new_root->rchild);
    return new_root;
}


struct Node* insert(struct Node* parent, int key){ // It takes a pointer to the current root of the subtree (parent). And it returns a pointer to the root of the (possibly updated) subtree.
    if (parent == NULL)
    {
       struct Node* new_node = malloc(sizeof(struct Node));
       if (!new_node) { perror("malloc"); exit(EXIT_FAILURE); } // When you call malloc, it might fail (e.g., system is out of RAM). If it fails, it returns NULL. An OOM(Out Of Memory) check is simply verifying if malloc returned NULL before using the pointer.
       new_node->value = key;
       new_node->lchild = NULL;
       new_node->rchild = NULL;
       new_node->height = 1; // not 0, because a single node counts as height 1
       return new_node;
    } else
    {
        if (key < parent->value)
        {
            parent->lchild = insert(parent->lchild, key);
        } else if (key > parent->value)
        {
            parent->rchild = insert(parent->rchild, key);
        } else // it is a duplicate, so do nothing
        {
            return parent;
        }
        parent->height = 1 + maxHeight(parent->lchild, parent->rchild);

        int bf = balanceFactor(parent);

        if (bf > 1) { // left-heavy(LR- or LL-imbalance)

            if (balanceFactor(parent->lchild) >= 0) return rotateRight(parent);

            else
            {
                parent->lchild = rotateLeft(parent->lchild);
                return rotateRight(parent);
            }
            
        } else if(bf < -1) { // right-heavy(RL- or RR-imbalance)

            if (balanceFactor(parent->rchild) <= 0) return rotateLeft(parent);

            else
            {
                parent->rchild = rotateRight(parent->rchild);
                return rotateLeft(parent);
            }
            
        }
        return parent;
    }
}

void inorder(struct Node* n) {
    if (!n) return;
    inorder(n->lchild);
    printf("%d ", n->value);
    inorder(n->rchild);
}

int main() {
    int test_data[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(test_data) / sizeof(test_data[0]);

    for (int i = 0; i < size; i++) {
        root = insert(root, test_data[i]); // "root" has been defined in the last bit of the struct above: *root = NULL, declares a global variable:
    }

    printf("Inorder traversal of AVL tree: ");
    inorder(root); // For AVL trees (and all BSTs): inorder = ascending
    printf("\n");

    return 0;
}