# Review Day 14 for Queue
# Created on 2025-07-13

'''
This is your review exercise for Queue.
Complete the implementation below to reinforce your understanding.
'''

# this implementation inserts at the head (beginning) and tries to delete at the rear (end):

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class Queue:
    def __init__(self):
        self.head = None
        self.rear = None

    def insert_head(self, value):
        new_node = Node(value)
        if self.head == None:
            self.head = new_node
            self.rear = new_node
        else:
            new_node.next = self.head
            self.head = new_node

    def delete_rear(self):
        if self.rear == None:
            raise IndexError("Queue already empty")
        elif self.head == self.rear:
            self.rear = None
            self.head = None
        else:
            current = self.head
            while current.next != self.rear:
                current = current.next
            self.rear = current
            current.next = None
    def print_queue(self):
        if self.head is None:
            print("Queue is empty")
            return
        current = self.head
        while current is not None:
            print(current.data, end=' ')
            current = current.next
        print()


if __name__ == "__main__":
    que = Queue()
    test_data = [5, 2, 9, 1, 5, 6]
    for value in test_data:
        que.insert_head(value)
    print("Before deletion:")
    que.print_queue()
    que.delete_rear()
    print("After deletion:")
    que.print_queue()