# Binary Search Tree

A Binary Search Tree (BST) is a binary tree in which every node in the left subtree is smaller than the node, and every node in the right subtree is larger. BSTs are useful for efficient searching, insertion, and deletion operations, where the search time depends on the height of the tree. The ordering here is unlike heap global, not local. (In heap, which is **NOT** a BST, we have no left < right rule)

## Properties
- No duplicate values are allowed.
- In-order traversal of a BST yields a sorted array of values.
- The number of unique BSTs that can be formed with n nodes is given by the nth Catalan number: (2n C n) / (n + 1).
- BSTs are usually represented using linked structures (nodes with left and right pointers).

## Searching Procedure
- Start from the root (or the node passed as a parameter).
- Compare the target value with the current node's value.
- If the target is smaller, move to the left subtree; if larger, move to the right subtree.
- Repeat this process until the node is null (target not found) or the value is found.

### Number of Comparisons
- The number of comparisons depends on the height of the tree.
- **Best/Average Case (balanced tree):** O(log n)
- **Worst Case (skewed tree):** O(n)

## Insertion Procedure
- Since BSTs do not allow duplicates, first search to ensure the value does not exist.
- Use a temporary pointer to traverse the tree and a tail pointer to keep track of the parent node.
- When the search ends unsuccessfully (reaches null), insert the new node as the left or right child of the tail node, depending on the value.
- Insertion time is O(log n) for a balanced tree, O(n) for a skewed tree.

## BST Creation
- BSTs can be created by inserting values one by one, following the insertion procedure.
- The shape and efficiency of the BST depend on the order of insertion; random or sorted insertions can lead to balanced or skewed trees, respectively.

## BST Deletion
- To delete a node, first search for the value in the tree.
- If the node has no children, simply remove it.
- If the node has one child, replace the node with its child.
- If the node has two children, replace it with either its in-order predecessor (the largest value in the left subtree, found by going left then right as far as possible) or its in-order successor (the smallest value in the right subtree, found by going right then left as far as possible). The choice of predecessor or successor is up to the implementation. If the chosen predecessor or successor is not a leaf node, further modifications are needed to reconnect its child (if any) to maintain the BST structure.

## Summary
- BSTs provide efficient search, insertion, and deletion when balanced.
- The performance of BST operations is closely tied to the tree's height.
- Self-balancing BSTs (like AVL or Red-Black trees) are used to maintain O(log n) operations in practice.

| **Aspect**             | **Binary Max-Heap**                                       | **Complete Binary Search Tree (CBST)**                         | **Strict Binary Tree**                          | **Full Binary Tree**                                          |
|------------------------|----------------------------------------------------------|----------------------------------------------------------------|------------------------------------------------|----------------------------------------------------------------|
| **Shape**             | Complete binary tree (all levels full, last left-filled) | Complete binary tree                                           | Each node has 0 or 2 children                 | Each node has 0 or 2 children; all leaves at same level (perfectly symmetrical)       |
| **Ordering property** | Parent ≥ immediate children (local ordering only)         | Left subtree < node < right subtree (global ordering)          | No ordering on values                        | No ordering on values                                         |
| **Sibling order**     | No constraint between left and right child               | Left child < parent < right child                             | Only shape matters                            | Only shape + leaf level matter                                |
| **Purpose / use case**| Fast max extraction (`O(1)`), heapsort, priority queues  | Efficient search, insert, delete (`O(log n)` if balanced)     | Shape modeling, theoretical structures        | Shape modeling, network topology, theoretical frameworks      |
| **Example structure** | `[10, 9, 8, 7, 6, 5]` (array), tree shape, local order  | `[4, 2, 6, 1, 3, 5, 7]` (array or tree), full subtree order  | Tree where node has 0 or 2 children only     | Perfect pyramid-shaped tree, all leaves at same depth         |
| **Data access**       | Only root guaranteed max                                | In-order traversal gives sorted order                         | N/A (Not Applicable)                                          | N/A (purely shape-based definitions, don’t impose value ordering, search rules, or insertion behaviors)                                                          |
| **Insertion logic**   | Insert at last, bubble up                               | Insert per BST rules, maintain completeness                  | N/A                                           | N/A                                                           |