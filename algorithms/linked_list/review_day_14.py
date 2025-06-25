# Review Day 14 for Linked List
# Created on 2025-06-25

'''
This is your review exercise for Linked List.
Complete the implementation below to reinforce your understanding.
'''


class Node():
    def __init__(self, value):
        self.value = value
        self.next = None
    def display(self):
        current = self
        while current != None:
            print(current.value)
            current = current.next
class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, value):
        if self.head is None:
            self.head = Node(value) # where we connect self.head in the LinkedList class to a Node object
        else:
            current = self.head
            while current.next != None:
                current = current.next
            new = Node(value)
            current.next = new
        
    def prepend(self, value):
            new = Node(value)
            new.next = self.head
            self.head = new
    
    def display(self):
        current = self.head
        while current is not None:
            print(current.value)
            current = current.next

ll = LinkedList()
ll.append(20)
ll.append(30)
ll.prepend(10)
ll.display()