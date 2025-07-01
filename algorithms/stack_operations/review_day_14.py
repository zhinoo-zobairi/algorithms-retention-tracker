# Review Day 14 for Stack Operations
# Created on 2025-07-01

'''
This is your review exercise for Stack Operations.
Complete the implementation below to reinforce your understanding.
'''

class Stack:
    def __init__(self, size):
        self.top = -1
        self.size = size 
        self.items = [None] * size

    def push(self, value):
        if self.top == self.size - 1:
            print("Stack is full")
        else:
            self.top += 1
            self.items[self.top] = value
    
    def pop(self):
        if self.top == -1:
            print("Stack is empty")
            return None
        else:
            deleted = self.items[self.top]
            self.top -= 1
            return deleted
    
class QueueUsingTwoStacks:
    def __init__(self, size):
        self.stack_1 = Stack(size)
        self.stack_2 = Stack(size)

    def enqueue(self, value):
        self.stack_1.push(value)

    def dequeue(self):
        if self.stack_2.top == -1 :
            while self.stack_1.top != -1:
                self.stack_2.push(self.stack_1.pop())
        if self.stack_2.is_empty():
            print("Queue is empty")
            return None
        return self.stack_2.pop()

class MinStack:
    def __init__(self, size):
        self.mainStack = Stack(size)
        self.minStack = Stack(size)
    
    def push(self, value):
        if self.minStack.top == -1 or value < self.minStack.items[self.minStack.top]:
            self.minStack.push(value)
        self.mainStack.push(value)
    
    def getMinConstantTime(self):
        if self.minStack.top == -1:
            return None
        minimum = self.minStack.items[self.minStack.top]
        return minimum
        

