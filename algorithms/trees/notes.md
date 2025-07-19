# Trees

A **tree** is a collection of nodes where one node is designated as the **root**.  
The remaining nodes are divided into **disjoint subsets**, each forming a **tree** or **subtree**.


## Key Concepts

- **Descendants:**  
  All nodes reachable from a given node.

- **Ancestors:**  
  All nodes along the path from a given node up to the root.

- **Degree of a node:**  
  Number of direct children.

- **Degree of a tree:**  
  Maximum degree among all nodes.

- **Level:**  
  Starts from 1.

- **Height of a tree:**  
  Starts from 0, counts the edges.


## Binary Tree

A tree where each node has at most **2 children** (left and right).  
Allowed children: 0, 1, or 2.  


### Binary Tree Formulas

- **Number of binary trees (using nodes):**  
  $$
  T(n) = \frac{2n \cdot C_n}{n + 1}
  $$

- **Number with maximum height:**  
  $$
  2^{n - 1}
  $$

- **Number with labeled nodes:**  
  $$
  \frac{2n \cdot C_n}{n + 1} \times n! 
  $$
  (shapes × fillings)


### Height vs. Nodes

- **Minimum nodes from height:**  
  $$
  h + 1
  $$

- **Maximum nodes from height:**  
  $$
  2^{h + 1} - 1
  $$

- **Minimum height from nodes:**  
  $$
  \log_2(n + 1) - 1
  $$

- **Maximum height from nodes:**  
  $$
  h = n - 1
  $$

- **Height range (binary tree):**  
  $$
  \log_2(n + 1) - 1 \leq h \leq n - 1
  $$

- **Node range (binary tree):**  
  $$
  h + 1 \leq n \leq 2^{h + 1} - 1
  $$

- **Relationship:**  
  Number of nodes with degree 2 is always one less than the number of nodes with degree 0.


## Strict Binary Tree

Each node has **either 0 or 2 children**.

- **Minimum nodes from height:**  
  $$
  2h + 1
  $$

- **Maximum nodes from height:**  
  $$
  2^{h + 1} - 1
  $$

- **Minimum height from nodes:**  
  $$
  \log_2(n + 1) - 1
  $$

- **Maximum height from nodes:**  
  $$
  \frac{n - 1}{2}
  $$

- **External nodes (leaves):**  
  Always one more than internal nodes.


## N-ary Trees

A tree where each node can have up to **n** children.

> **Important:** The degree \( n \) must be given; it’s like the capacity of an array.


### Strict N-ary Trees

Each node has **either 0 or exactly n children**.

- **Minimum nodes from height:**  
  $$
  (\text{degree}) \cdot h + 1
  $$

- **Maximum nodes from height:**  
  $$
  \frac{\text{degree}^{h + 1} - 1}{\text{degree} - 1}
  $$

- **Minimum height from nodes:**  
  $$
  \log_{\text{degree}} \big( (n \cdot (\text{degree} - 1)) + 1 \big) - 1
  $$

- **Maximum height from nodes:**  
  $$
  \frac{n - 1}{\text{degree}}
  $$

- **External nodes (leaves):**  
  $$
  (\text{degree} - 1) \cdot \text{internal nodes} + 1
  $$

## Binary Tree Representation

- **Using array:**  
  - Left child → \( 2 \times \text{index} \)  
  - Right child → \( 2 \times \text{index} + 1 \)

- **Using linked list (doubly linked):**  
  With \( n \) nodes, there will be \( n + 1 \) null pointers.


## Special Types

- **Full Binary Tree:**  
  Always complete, max nodes \( 2^{h + 1} - 1 \).

- **(Almost) Complete Binary Tree:**  
  Full up to \( h - 1 \), last level filled **left to right**.

- **Strict (Proper) Binary Tree:**  
  Each node has 0 or 2 children, may or may not be complete.


## Tree Traversals

- **Preorder:** Root → Left → Right  
- **Inorder:** Left → Root → Right  
- **Postorder:** Left → Right → Root  
- **Level Order:** Level by level

**Tip:** Draw a line under the tree:  
- Preorder → connect left-hand side  
- Inorder → connect center  
- Postorder → connect right-hand side  
Read from left to right.


## Creating Binary Tree (Linked List)

1. Create root node, set left/right (`prev`/`next`) pointers to null, enqueue address.
2. Dequeue address, point a temp pointer to it.
3. Check if this node has children.
4. Create new nodes, set `prev`/`next` to null, enqueue their addresses.
5. Link root’s left (`prev`) and right (`next`) to new nodes.
6. Repeat for all nodes.