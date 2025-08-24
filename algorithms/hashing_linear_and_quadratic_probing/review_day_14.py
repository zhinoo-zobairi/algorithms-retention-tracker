# Review Day 14 for Hashing Linear and Quadratic Probing
# Created on 2025-07-12

'''
This is your review exercise for Hashing Linear and Quadratic Probing.
Complete the implementation below to reinforce your understanding.
'''

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None for _ in range(size)]


    def hash_function(self, key):
        return key % self.size
    def linear_probing(self, index):
        start_index = index
        while self.table[index] is not None:
            index = (index + 1) % self.size
            if index == start_index:
                raise Exception("Hash table is full")
        return index


    def insert(self, key):
        index = self.hash_function(key)
        if self.table[index] is not None:
            index = self.linear_probing(index)
        self.table[index] = key


    def display(self):
        for i, value in enumerate(self.table):
            print(f"Index {i}: {value}")


if __name__ == "__main__":
    table = HashTable(10)
    table.insert(60)
    table.insert(10)
    table.insert(600)
    table.display()