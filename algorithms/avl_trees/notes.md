# AVL Trees

An AVL tree is a self-balancing binary search tree where the heights of the two child subtrees of any node differ by at most one. If at any time they differ by more than one, rebalancing is performed to restore this property. AVL stands for the inventors' names: Adelson-Velsky and Landis.

## Balance Factor
- The balance factor (bf) of a node is the height of its left subtree minus the height of its right subtree.
- Valid balance factors for AVL trees are -1, 0, or +1. A bf of 2 or -2 (or more extreme) is invalid.
- Height is counted as the number of edges from the node to the deepest leaf (not the number of nodes).

## Rotations After Insertion
- Rotations are used to restore balance after insertion or deletion.
- Rotations always involve at most 3 nodes.

### LL Rotation (Right/Clockwise Rotation)
- Occurs when a node is inserted into the left subtree of the left child.
- Rotate the imbalanced node to the right. After rotation, the bf of the node becomes 0.

### RR Rotation (Left/Counterclockwise Rotation)
- Occurs when a node is inserted into the right subtree of the right child.
- Rotate the imbalanced node to the left.

### LR Rotation (Double Rotation)
- Occurs when a node is inserted into the right subtree of the left child.
- First, rotate the left child to the left, then rotate the imbalanced node to the right.

### RL Rotation (Double Rotation)
- Occurs when a node is inserted into the left subtree of the right child.
- First, rotate the right child to the right, then rotate the imbalanced node to the left.

## Rotations for Multiple Nodes
- Only 3 nodes are involved in a single rotation step.
- If the bf is negative, insertion was on the right side; if positive, insertion was on the left side.
- After rotation, children are placed where they belong.
- For deep insertions (e.g., left of left of left of left), only consider two steps from the top imbalanced node to determine the rotation type (LL, RR, etc.).
- The node on which rotation is performed should have bf 0 after rotation.

## Insertion
- Perform rotation on the first ancestor that becomes imbalanced after insertion.

## Deletion
- Deletion is similar to BST: find the node, delete it, and let the successor take its place.
- If deletion causes imbalance:
    - If right side is deleted and left becomes heavy, perform LL rotation (called l1 rotation if left child has bf 1).
    - l-1 rotation: imbalanced node has bf -1, left child has bf -1 (right side heavy), perform LR rotation.
    - l0 rotation: can do either l1 or l-1 depending on child bf.
    - R1, R-1, R0 are mirror images (deletion from left side).

## Searching
- AVL trees are useful for searching keys efficiently, requiring fewer comparisons due to strict balancing.

## Node and Height Relationships
### If Height is Given
- Maximum nodes: 2^h - 1 (perfectly balanced tree)
- Minimum nodes: F(h+2) - 1, where F(n) is the nth Fibonacci number
    - Formula: n(h) = n(h-1) + n(h-2) + 1
    - Examples:
        - Height 1: 1 node
        - Height 2: 2 nodes
        - Height 3: 4 nodes
        - Height 4: 7 nodes
        - Height 5: 12 nodes
        - Height 6: 20 nodes

### If Node Count is Given
- Minimum height (best case): h = ⌊log2(n)⌋ + 1
- Maximum height (worst case for AVL): h ≈ 1.44 * log2(n)
- For exact max height, refer to AVL height tables or use the Fibonacci relationship.

## Why Use AVL Trees?
- Guarantees O(log n) search, insert, and delete operations.
- Prevents degeneration into a linked list.
- Useful for applications needing fast lookups and frequent updates (e.g., databases, memory management).