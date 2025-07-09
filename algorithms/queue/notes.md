# Queue

## Overview
Queue is an Abstract Data Type (ADT) that follows the **FIFO (First In, First Out)** principle. The element that is inserted first will be the first one to be removed.

## Basic Operations
- **Enqueue**: Add an element to the rear/back of the queue
- **Dequeue**: Remove an element from the front of the queue
- **Front/Peek**: View the front element without removing it
- **IsEmpty**: Check if the queue is empty
- **IsFull**: Check if the queue is full (for array implementation)

## Implementation Methods

### 1. Array Implementation

### Single Pointer Approach
- Uses only one pointer to track the rear
- Front is always at index 0

**Drawbacks:**
- Dequeue operation requires shifting all elements: O(n)
- Inefficient for frequent dequeue operations

**Time Complexity:**
- Enqueue: O(1)
- Dequeue: O(n) - due to shifting
- Front: O(1)

### Two Pointer Approach
- Uses `front` and `rear` pointers
- No shifting required for dequeue

**Important Note on Front Pointer Convention:**
There are two common approaches for the `front` pointer:
1. **Front points to first valid element**: `front` directly points to the element to be dequeued
2. **Front points before first element**: `front` points to the position before the first valid element (the cell at `front` is empty/invalid)

**Drawbacks:**
- **False overflow**: Array appears full even when space is available at the beginning
- Memory wastage due to unused spaces

**Time Complexity:**
- Enqueue: O(1)
- Dequeue: O(1)
- Front: O(1)

#### Circular Array (Solution to False Overflow)
- Treats array as circular using modulo arithmetic
- Solves the false overflow problem of linear two-pointer approach

**How Circular Queue Works:**
1. **Move to the next index**: Use `+1` to advance pointers
2. **Wrap to 0 if at the end**: Use `% size` to wrap around when reaching array boundary

**Key Formulas:**
- `rear = (rear + 1) % size` for enqueue
- `front = (front + 1) % size` for dequeue

**Example:** In array of size 5:
- When `rear = 4` and we enqueue: `rear = (4 + 1) % 5 = 0` (wraps to beginning)
- When `front = 4` and we dequeue: `front = (4 + 1) % 5 = 0` (wraps to beginning)

**Advantages:**
- Efficiently utilizes all array positions
- No memory wastage from false overflow
- All unused spaces can be reused

**Empty vs Full Conditions:**
- **Empty**: `front == rear`
- **Full**: `(rear + 1) % size == front`

**Time Complexity:**
- All operations: O(1)

### 2. Linked List Implementation

### Single Pointer (Rear only)
- Keep pointer to rear for enqueue
- Traverse from rear to front for dequeue

**Drawbacks:**
- Dequeue requires traversal: O(n)
- Inefficient for frequent dequeue operations

### Two Pointers (Front and Rear)
- Maintain pointers to both front and rear
- Optimal for queue operations

**Advantages:**
- Dynamic size
- No overflow issues
- Efficient operations

**Time Complexity:**
- Enqueue: O(1)
- Dequeue: O(1)
- Front: O(1)

## Summary of Approaches

| Implementation | Enqueue | Dequeue | Space | Overflow Issue |
|---|---|---|---|---|
| Array (1 pointer) | O(1) | O(n) | Fixed | Yes |
| Array (2 pointers) | O(1) | O(1) | Fixed | False overflow |
| Circular Array | O(1) | O(1) | Fixed | No |
| Linked List (1 pointer) | O(1) | O(n) | Dynamic | No |
| Linked List (2 pointers) | O(1) | O(1) | Dynamic | No |

## Applications
- Process scheduling in operating systems
- Breadth-First Search (BFS) in graphs
- Buffer for data streams
- Print job management
- Handling requests in web servers

