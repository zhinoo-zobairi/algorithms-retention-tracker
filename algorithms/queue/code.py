# Queue implementation

class LinearQueue(): # Basic FIFO logic without wrap
    def __init__(self, size):
        self.size = size
        self.rear = -1
        self.front = -1
        self.array = [None] * size
    
    def enqueue(self, value):
        if self.rear == self.size - 1:
            print("The queue is full")
        else:
            self.rear += 1
            self.array[self.rear] = value
    
    def dequeue(self):
        if self.front == self.rear:
            print("Queue is already empty")
            return None
        else:
            self.front += 1
            return self.array[self.front]

    def display(self):
        for i in range(self.front + 1, self.rear + 1): # front + 1 because front points to last dequeued
            print(self.array[i])

q = LinearQueue(3)

q.enqueue(10)
q.enqueue(20)
q.enqueue(30)
q.display()

print("Dequeued:", q.dequeue())
q.display()

# separation of behavior > shared fields

class CircularQueue(LinearQueue):  # FIFO with space reuse + Inherits all fields of LinearQueue
    def __init__(self, size):
        super().__init__(size)  # calls LinearQ.__init__()
        self.front = 0 # to avoid -1 in our mod
        self.rear = 0

    def enqueue(self, value): # here we can only save size - 1 elements, because we need to distinguish between empty and full states
        if (self.rear + 1) % self.size == self.front:
            print("Queue is full")
        else:
            self.rear = (self.rear + 1) % self.size
            self.array[self.rear] = value
        
    def dequeue(self):
        if self.front == self.rear:
            print("Queue is already empty")
            return None
        else:
            self.front = (self.front + 1) % self.size
            return self.array[self.front]
    
    def display(self):
        if self.front == self.rear: # Defensive
            print("Queue is empty")
            return
        
        i = (self.front + 1) % self.size
        while i != (self.rear + 1) % self.size:
            print(self.array[i])
            i = (i + 1) % self.size # I’ll loop from (front + 1) % size and stop after I pass rear. So my stop condition is the next slot after rear or (rear + 1) % size.

print("\n=== Testing CircularQueue ===")

cq = CircularQueue(4)
cq.enqueue(10)
cq.enqueue(20)
cq.enqueue(30)
cq.display()
cq.enqueue(40)
print("Dequeued:", cq.dequeue())
print("Dequeued:", cq.dequeue())
print("After 2 dequeues:")
cq.display()
print("\n4. Testing circular behavior:")
cq.enqueue(40)  # Should work now even though rear is on last index (reusing space)
cq.enqueue(50)  # Should work (reusing space)
cq.display()


class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

class LinkedListQueue:
    def __init__(self):
        self.front = None
        self.rear = None

    def enqueue(self, value):
        new_node = Node(value)
        if self.front == None: # Detects if queue is empty
            self.front = new_node
            self.rear = new_node
        else:
            self.rear.next = new_node # the logic path ensures that by the time we get here, self.rear must already be a Node.

    def dequeue(self):
        if self.front == None: 
            print("Queue is already empty")
        else:
            deleted = self.front.data
            self.front = self.front.next
            if self.front is None: # if this was the last node in the queue:
                self.rear = None
            return deleted
    
    def is_empty(self):
        return self.front is None

    def display(self):
        if self.front == None:
            print("Queue is already empty")
        else:
            current = self.front # in order to not mutate the front itself and ruin the queue
            while current is not None:
                print(current.data)
                current = current.next

