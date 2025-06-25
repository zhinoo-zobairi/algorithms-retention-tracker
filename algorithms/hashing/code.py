# Hashing implementation

class Node:
    def __init__(self,value):
        self.value = value
        self.next = None
class HashTable:
    def __init__(self, size):
        self.size = size
        self.buckets = [None] * size

    def hash_function(self, key):
        return key % self.size

    def insert_head(self, key):
        index = self.hash_function(key)
        new_node = Node(key)
        new_node.next = self.buckets[index]
        self.buckets[index] = new_node

    def insert_tail(self, key):
        index = self.hash_function(key)
        new_node = Node(key)
        
        if self.buckets[index] is None:
            # Case 1: Empty bucket
            self.buckets[index] = new_node
        else:
            # Case 2: Traverse to tail and insert
            temp_node = self.buckets[index]
            while temp_node.next is not None:
                temp_node = temp_node.next
            temp_node.next = new_node
        
