# Review Day 14 for Double-Ended Queue
# Created on 2025-07-15

'''
This is your review exercise for Double-Ended Queue.
Complete the implementation below to reinforce your understanding.
'''
from typing import Optional

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None

class DEQueue:
    def __init__(self):
        self.front = None
        self.rear = None

    def isEmpty(self) -> bool:
        return self.front is None
    
    def addFront(self, value):
        """
        In both array-based and linked-list-based deques, the conventional and correct behavior is:
        front always points to the newly inserted front element after insertion.
        """
        new_node = Node(value)
        if self.front is None and self.rear is None:
            self.front = new_node
            self.rear = new_node
            return
        self.front.prev = new_node
        new_node.next = self.front
        self.front = new_node
    
    def addRear(self, value):
        """
        When adding at the rear, the rear should always end up pointing to the newly inserted last element in the deque.
        """
        new_node = Node(value)
        if self.front is None and self.rear is None:
            self.front = new_node
            self.rear = new_node
            return
        self.rear.next = new_node
        new_node.prev = self.rear
        self.rear = new_node
    
    def deleteFront(self):
        if self.front is None:
            return None
        deleted = self.front.value
        if self.front == self.rear:
            self.front = None
            self.rear = None
            return deleted
        self.front = self.front.next
        self.front.prev = None
        return deleted

    def deleteRear(self):
        if self.rear is None:
            return None
        if self.front == self.rear:
            data = self.rear.value
            self.front = None
            self.rear = None
            return data
        deleted_element = self.rear.value
        self.rear = self.rear.prev
        self.rear.next = None
        return deleted_element
    
