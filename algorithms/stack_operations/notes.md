# Stack Operations

## Understanding Stack Data Structure

A stack data structure consists of two main components:

1. **The actual data storage** - where elements are stored (like an array or linked list)
2. **The stack structure/metadata** - properties that manage the data

Think of it like **a car and its registration document**:

- **The car itself** = the actual array/memory where stack elements are stored
- **The registration document** = the stack structure containing:
  - `size`: maximum capacity (like the car's seating capacity)
  - `top`: index of the topmost element (like noting which seat is currently occupied)
  - `pointer`: reference to the storage location (like the car's VIN pointing to the physical vehicle)

The registration document doesn't contain the car, it just tracks important information about it. Similarly, the stack structure doesn't store the actual elements, but manages crucial metadata like where the top element is located and how much space is available and what the location of the array is.

>“The Stack struct itself is not a pointer, but when we pass it to push, we pass its address, so that push can modify it.” I created the real book in main(), and when I gave it to the push() function, I gave them the address of the book, not the book itself.”
