# Priority Queue implementation
# How to run? jinnokursani@MacBookAir algorithms % python -m priority_queue.code 
from queue.code import LinkedListQueue
# It is just a contract, we never instantiate it:
class PriorityQueue:
    def insert(self, item, priority=None): pass
    def peek(self): pass
    def delete(self): pass
    def is_empty(self): pass
    def size(self): pass

# This JavaStylePriorityQueue class is not one “item”. It is the whole priority queue system. The object is not a value, it is the entire structure managing many values.
class JavaStylePriorityQueue(PriorityQueue):
    def __init__(self, max_priority=10): 
        self.max_priority = max_priority
        self.queues = [LinkedListQueue() for _ in range(max_priority + 1)]

    def insert(self, item, priority): 
        if priority < 0 or priority > self.max_priority:
            raise ValueError("Invalid priority level")
        self.queues[priority].enqueue(item)

# we remove an item from the highest-priority non-empty queue:
    def delete(self): 
       # i = self.max_priority
       # while self.queues[i].dequeue() is None:
           # i -= 1
           # This is risky, because if all queues are empty you will go below 0 and get IndexError; It is also wasteful, because you’re modifying state (removing items) even if the queue is empty
        for i in range(self.max_priority, -1, -1): 
            if self.queues[i].front is not None:
                return self.queues[i].dequeue()
        raise IndexError("Priority Queue is empty")

    def peek(self):
        for i in range(self.max_priority, -1, -1):
            if self.queues[i].front is not None:
                return self.queues[i].front.data
        raise IndexError("Priority Queue is empty")

# checks if all priority queues are empty:    
    def is_empty(self): 
        for i in range(self.max_priority + 1):
            if self.queues[i].front is not None:
                return False
        return True
    
# returns the total number of elements across all priority queues:      
    def size(self):
        count = 0
        for i in range(0, self.max_priority + 1):
            current = self.queues[i].front
            while current != None:
                count += 1
                current = current.next
            return count



# Insert in O(1) and search for max priority on delete (lazy strategy), or
# Insert in sorted order, so delete is O(1) (eager strategy)
# We're building a sructure like [("print-job-1", 3), ("pdf-export", 5), ("email-sync", 2)] = self.queue 
class LazyExplicitPriorityQueue(PriorityQueue):
    def __init__(self): 
        self.queue = [] # tuple-based flat version, which stores everything in one list

    def insert(self, item, priority):   # O(1) or O(n) depending on policy: lazy or eager
        self.queue.append((item, priority))
    
    def delete(self):
        if not self.queue:
            raise IndexError("Priority queue is empty")
        min_prio = self.queue[0][1]
        index = 0
        for i in range(1, len(self.queue)):
            prio = self.queue[i][1]
            if prio < min_prio:
                index = i
                min_prio = prio
        dequeued = self.queue[index][0]
        self.queue.pop(index)
        return dequeued

class EagerExplicitPriorityQueue(PriorityQueue):
    def __init__(self): 
        self.queue = []

    def insert(self, item, priority):
        self.queue.append((item, priority))
        # (insertion) sort manually:
        i = len(self.queue) - 2
        while i >= 0 and self.queue[i][1] > priority:
            self.queue[i + 1] = self.queue[i]
            i -= 1
        self.queue[i + 1] = (item, priority)

if __name__ == "__main__":
    print("=== Testing JavaStylePriorityQueue ===")
    java_pq = JavaStylePriorityQueue(max_priority=5)
    java_pq.insert("Emergency call", 5)
    java_pq.insert("Email sync", 1)
    java_pq.insert("Video call", 4)
    java_pq.insert("File backup", 2)
    java_pq.insert("System update", 3)
    
    print(f"Is empty: {java_pq.is_empty()}")
    print(f"Peek highest priority: {java_pq.peek()}")
    
    while not java_pq.is_empty():
        print(f"Processing: {java_pq.delete()}")
    
    print("\n=== Testing LazyExplicitPriorityQueue ===")
    lazy_pq = LazyExplicitPriorityQueue()
    
    lazy_pq.insert("Critical bug fix", 1)
    lazy_pq.insert("Code review", 3)
    lazy_pq.insert("Documentation", 5)
    lazy_pq.insert("Database backup", 2)
    
    while lazy_pq.queue:
        print(f"Processing: {lazy_pq.delete()}")
    
    print("\n=== Testing EagerExplicitPriorityQueue ===")
    eager_pq = EagerExplicitPriorityQueue()
    
    eager_pq.insert("User login", 2)
    eager_pq.insert("Security alert", 1)
    eager_pq.insert("Data export", 4)
    eager_pq.insert("Report generation", 3)
    
    print("Queue after insertions (should be sorted):")
    for item, priority in eager_pq.queue:
        print(f"  {item} (priority: {priority})")







