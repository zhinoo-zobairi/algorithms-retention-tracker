## Data Structures vs. Abstract Data Types

### What's the difference?

**Data Structures** = **How** data is physically stored and organized in memory
- Examples: Arrays, Linked Lists, Hash Tables, Trees
- Concrete implementations with specific memory layouts
- Define how elements are accessed and manipulated

**Abstract Data Types (ADTs)** = **What** operations you can perform, not how they're implemented
- Examples: Stack, Queue, List, Set, Map
- Define behavior and interface, not implementation
- Focus on operations like push/pop, enqueue/dequeue

### Key Distinction:
- **Stack** = Abstract Data Type (LIFO behavior)
  - Can be implemented using:
    - **Arrays** (data structure - fixed size, faster index access)
    - **Linked Lists** (data structure - dynamic size, pointer-based)

- **Queue** = Abstract Data Type (FIFO behavior)
  - Can also be implemented using either data structure


## Analogy:
- **Stack/Queue (ADTs)** is like the **rules** of how people enter/exit a building
- **Array/Linked List (Data Structures)** is the **floorplan** of the building

So yes, Stack and Queue are **higher-level concepts** — they use arrays or linked lists underneath.


## Python Implementation Notes:

- `[] * size` creates an empty list (not filled with `None`)
- Python lists are dynamic, but we simulate static behavior to mirror C-style arrays
- No pointers in Python, but variable references work similarly under the hood
- Use `[None] * size` to create a pre-filled array-like structure


## Engineering Decision:

In interviews or real-world usage:

**"Stack using array"** vs. **"Stack using linked list"** is often an engineering decision based on tradeoffs like:
- Memory usage
- Speed requirements
- Resizing behavior needs
