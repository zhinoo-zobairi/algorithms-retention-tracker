# Review Day 14 for Priority Queue
# Created on 2025-07-15

'''
This is your review exercise for Priority Queue.
Complete the implementation below to reinforce your understanding.
'''
class Node:
    def __init__(self, value, prio):
        self.priority = prio
        self.value = value
        self.next = None

class PriorityQueue:
    def __init__(self):
        self.head = None

    def insert(self, value, prio):
        new_node = Node(value, prio)
        if self.head is None:
            self.head = new_node
        elif self.head.priority > prio:
            following = self.head
            self.head = new_node
            new_node.next = following
        
        else:
            current = self.head
        # current(A).next(B).prio = 5 < 6 --> current(B).next(C).prio = 7 > 6 STOP current is now B
            while current.next is not None and current.next.priority < prio: # insert node with prio 6 in: A2(head/current)  B5    C7   D8 
                current = current.next
            
            following = current.next 
            current.next = new_node
            new_node.next = following
            
    def delete(self):
        if self.head is None:
            raise IndexError("Priority queue is empty")
        value = self.head.value
        self.head = self.head.next
        return value

    def display(self):
        current = self.head
        while current is not None:
            print(f"({current.priority}, {current.value})", end=' -> ')
            current = current.next
        print('None')

    

if __name__ == "__main__":
    pq = PriorityQueue()
    
    pq.insert('A', 3)
    pq.insert('B', 1)
    pq.insert('C', 4)
    pq.insert('D', 2)
    
    pq.display()
    
    pq.delete()
    pq.display()
