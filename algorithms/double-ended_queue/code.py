# Double-Ended Queue implementation
from typing import Optional

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class Deque:
    def __init__(self):
        self.front = None # Don’t create a node unless you actually have data to put inside it.
        self.rear = None

    def is_empty(self) -> bool:
        return self.front is None

    def add_front(self, data) -> None: # we add the node and decrement front
        """
        In an array-based deque front is often treated as a numeric index. We decrement front when inserting at the front OR increment rear when inserting at the rear. In a linked list-based deque, however: front ends up pointing to the newly inserted node. front is a pointer to a node, not an index. There’s no numeric shifting, only pointer re-pointing. We don’t do front = front - 1. Instead, we insert a new node in front of the current one, and say: self.front = new_node
        """
        new_node = Node(data)
        if self.front is None and self.rear is None:
            self.front = new_node
            self.rear = new_node
        else:
            new_node.next = self.front # we do everything as if we want the new node to be behind the old node: new node's next is gonna point to the front and the front's prev is gonna point to the new node
            self.front.prev = new_node # At this point, they’re just connected; neither is officially “in front.”
            self.front = new_node # “Hey, this node is now the front pointer.”

    def add_rear(self, data) -> None:
        """i will do everything as if i wanted to put this new node in front of rear, but at the end i will flip the script and update rear to be the new node"""
        new_node = Node(data)
        if self.front is None and self.rear is None:
            self.front = new_node
            self.rear = new_node
        else:
            self.rear.next = new_node
            new_node.prev = self.rear
            self.rear = new_node


    def remove_front(self) -> any:
        if self.front is None: # nothing to remove
            return None
        elif self.front == self.rear: # only one node in the deque
            data = self.front.data
            self.front = None
            self.rear = None
            return data
        else:
            removed = self.front.data
            self.front = self.front.next
            self.front.prev = None
            return removed

    """
	- When removing from front, we walk forward (front = front.next)
	- When removing from rear, we walk backward (rear = rear.prev)
    """

    def remove_rear(self) -> int:
        if self.rear is None:
            return None
        elif self.front == self.rear:
            data = self.rear.data
            self.front = None
            self.rear = None
            return data
        else:
            data = self.rear.data
            self.rear = self.rear.prev
            self.rear.next = None 
            return data


    def peek_front(self) -> Optional[int]:
        if self.front is None:
            return None
        else:
            return self.front.data

    def peek_rear(self) -> any:
        if self.rear is None:
            return None
        else:
            return self.rear.data

    def display(self) -> None:
        current = self.front
        if current is None:
            print("Deque is empty.")
            return
        while current is not None:
            print(current.data)
            current = current.next