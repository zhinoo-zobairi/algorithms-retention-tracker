# Review Day 14 for Array Operations
# Created on 2025-07-04

'''
This is your review exercise for Array Operations.
Complete the implementation below to reinforce your understanding.
'''

class Array():
    def __init__(self, size):
        self.size = size
        self.count = 0
        self.items = [None] * size

    def insert(self, value):
        if self.count >= self.size:
            raise OverflowError("Array is full")
        else:
            self.items[self.count] = value
            self.count += 1
    def insert_array(self, array):
        for i in range(0, len(array)):
            self.insert(array[i])
    
    def delete(self, index):
        if index < 0 or index > self.count - 1:
            raise IndexError("Index out of bounds")
        if self.items[index] is None:
            raise IndexError("The index is already empty")
        else:
            for i in range(index, self.count - 1):
                self.items[i] = self.items[i + 1]
            self.items[self.count-1] = None # even though we decrement self.count, the underlying list still holds the old value at the last position.
            self.count -= 1
            

if __name__ == "__main__":
    array = Array(10)
    test = [1, 2, 3, 4]
    array.insert_array(test)
    array.delete(1)
    print(array.items)