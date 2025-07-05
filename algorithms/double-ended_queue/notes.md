# Double-Ended Queue (Deque)

## Overview
A Double-Ended Queue is a data structure that allows insertion and deletion operations at both ends (front and rear). Unlike a regular queue, it doesn't strictly follow FIFO (First In, First Out) principle. Rear is, by definition, the last node in the deque and there is no node after it.

## Basic Operations

### Insertion Operations
- **Add at rear**: Add element and increment rear pointer
- **Add at front**: Add element and decrement front pointer

### Deletion Operations
- **Delete from rear**: Delete element and decrement rear pointer
- **Delete from front**: Delete element and increment front pointer

## Types of Restricted Deques

### 1. Input-Restricted Deque
- **Restriction**: Insertion is limited to one end only
- **Allowed operations**: 
  - Insert at rear only
  - Delete from both front and rear

### 2. Output-Restricted Deque
- **Restriction**: Deletion is limited to one end only
- **Allowed operations**:
  - Insert at both front and rear
  - Delete from front only

## Implementation Options
- **Array-based implementation**
- **Linked List-based implementation**

## Key Characteristics
- Flexible insertion and deletion at both ends
- More versatile than regular queues
- Can simulate both stack and queue behavior
