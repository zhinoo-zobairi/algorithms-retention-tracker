# Review Day 14 for Hashing
# Created on 2025-07-04

'''
This is your review exercise for Hashing.
Complete the implementation below to reinforce your understanding.
'''

class Node:
    def __init__(self, key, value): # this Node class supports key-value pairs and turns the structure into a Hash Map (dictionary-style), not only hash table
        self.key = key
        self.value = value
        self.next = None

class ChainedHashMap:
    def __init__(self, size):
        self.size = size
        self.buckets = [None] * size
    
    def hash_function(self, key):  # in Python, we don’t need to write our own string hashing logic. It works on all hashable types, including strings, ints, tuples, etc.
        return hash(key) % self.size

    def insert(self, key, value):
        """
        First checks if the bucket is empty, if yes then it's easy, it will simply inset it. If not, we have one thing to check: if a key in the bucket's chain is the same as the key we got and we will do that by traversing through all nodes in the chain of that specific bucket. If we find one, then we will substitute its value with the new value but if we never find a key like out parameter, then we have to continue the traversal, each time update the current node to its next node, and when the while is over because current is equal to None, we will insert the new node. There is a trick here though: if the current is None, then we can't do current.next = new_node. So we have to parallel to updating current to its next node, update another temporary node "prev" that saves the current node and won't be updated to any next, and we can do prev.next = new_node
        """
        index = self.hash_function(key)
        new_node = Node(key, value)
        
        if self.buckets[index] is None:
            self.buckets[index] = new_node
        else:
            current = self.buckets[index]
            prev = None
            while current is not None:
                if current.key == key:
                    current.value = value
                    return
                prev = current
                current = current.next
            prev.next = new_node
    

    def get(self, key): # retrieve the value associated with a key
        index = self.hash_function(key)
        current = self.buckets[index]
        while current != None:
            if current.key == key:
                return current.value
            current = current.next
        raise KeyError(f"Key '{key}' not found.")
    
    def remove(self, key):
        index = self.hash_function(key)
        current = self.buckets[index]
        prev = None

        while current is not None and current.key != key:
            prev = current
            current = current.next

        if current is None:
            raise KeyError(f"Key '{key}' not found.")

        if prev is None: # This condition fails (because current.key == key) → so loop doesn’t run at all and prev stays None as of line 56
            self.buckets[index] = current.next # removing head
        else:
            prev.next = current.next

        return current.value
    
