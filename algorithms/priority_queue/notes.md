# Priority Queue

## Overview
A Priority Queue is a data structure where each element has an associated priority. Elements are served based on their priority rather than their order of arrival. Higher priority elements are dequeued before lower priority elements.

## Key Characteristics
- Each element has its own priority
- Elements are processed in order of priority, not insertion order
- If two elements have the same priority, they are processed in FIFO order

## Implementation Approach
- **Multiple Queues**: We have as many queues as our different priority levels
- **Insertion Rule**: We are only allowed to add elements to the corresponding queue based on their priority
- **Deletion Rule**: We are only allowed to delete from the highest priority queue and that in FIFO fashion; if it's empty, then we move to the next highest priority queue

## Priority Systems
- **Java Threading**: Priorities range from 1 to 10, where 10 is the highest priority
- **General**: Priority values can vary by implementation (higher numbers = higher priority, or vice versa)

## Types of Priority Queues

### 1. Separate Priority and Value (explicit priority)
- Elements have distinct priority values separate from their actual data
- Example: Task with data="Send Email" and priority=5

### 2. Value-Based Priority(implicit priority)
- **Element value IS the priority**
- Two approaches:
  - **Higher value = Higher priority**: Max Priority Queue
  - **Lower value = Higher priority**: Min Priority Queue

#### Implementation Strategies for Value-Based Priority:

**Strategy A: Maintain Sorted Order**
- Insert elements in ascending/descending order during insertion
- **Insertion**: O(n) - need to find correct position
- **Deletion**: O(1) - always remove from front/rear

**Strategy B: Unsorted with Search on Deletion**
- Insert elements in constant time (no sorting)
- **Insertion**: O(1) - add anywhere
- **Deletion**: O(n) - search for min/max element to remove

**Strategy C: Heap-Based Implementation**
- **Best of both worlds**: Efficient insertion and deletion
- **Max-Heap**: For max priority queue (largest value = highest priority)
- **Min-Heap**: For min priority queue (smallest value = highest priority)
- **Key advantage**: Root always contains highest priority element
- **Insertion**: O(log n) - add element and bubble up
- **Deletion**: O(log n) - remove root and bubble down
- **Peek**: O(1) - just return root element

#### Why Heaps are Ideal for Priority Queues:
- **Heap Property**: Ensures highest/lowest priority is always at root
- **Balanced Structure**: Maintains O(log n) operations
- **Memory Efficient**: Array-based implementation
- **Real Example**: Hospital emergency room - critical patients always treated first

## Real-World Applications

### Operating Systems
- **Process Scheduling**: Higher priority processes get CPU time first
- **Thread Management**: Based on thread priorities for execution order
#### For example:
>Modern Example: Video Conferencing
>
>When you're on a Zoom call while downloading files:
>
>Zoom audio/video: Highest priority (real-time communication)
>
>File download: Lower priority (can tolerate delays)
>
>Background email sync: Lowest priority (non-critical)
>
>This is why your video call quality stays good even when other tasks are running!


## Starvation Problem
- **Definition**: Lower priority elements may never get processed if higher priority elements keep arriving
- **Scenario**: Continuous stream of high-priority tasks prevents low-priority tasks from execution
- **Impact**: System becomes unfair to lower priority processes

### Solutions to Starvation
- **Aging**: Gradually increase the priority of waiting elements over time
- **Time Slicing**: Allocate specific time slots for different priority levels
- **Priority Boosting**: Temporarily boost priority of starved processes
- **Fairness Algorithms**: Ensure all priority levels get some processing time

### Other Use Cases
- **Emergency Systems**: Critical alerts processed before routine notifications
- **Network Traffic**: High-priority packets sent before low-priority ones
- **Task Scheduling**: Important tasks executed before less critical ones

## Implementation Options
- **Array of Queues**: Separate queue for each priority level
- **Heap-based**: Using min-heap or max-heap for efficient priority ordering
- **Linked List**: With priority-based insertion

## Time Complexity
- **Insertion**: O(1) for array of queues, O(log n) for heap-based
- **Deletion**: O(k) for array of queues (k = number of priority levels), O(log n) for heap-based
- **Peek**: O(k) for array of queues, O(1) for heap-based