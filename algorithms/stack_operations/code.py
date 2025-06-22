# Stack Operations implementation

def stack_operations():
    
    class Stack:
        def __init__(self, size):
            self.size = size
            self.top = -1
            self.array = [None] * size  # in comparison to C, here we don't have address, it happens under the hood(reference)
        
        def push(self, value):
            if self.top == self.size - 1:
                print("Stack Overflow")
            else:
                self.top += 1
                self.array[self.top] = value

        def pop(self):
            if self.top == self.size - 1:
                print("Stack is Empty")
                return None
            # self.size -= 1 that’s like saying “my car has fewer seats now” every time someone gets out!
            value = self.array[self.top]
            self.items[self.top] = None  # optional cleanup
            self.top -= 1
            return value
        
        def peek(self, index):
            if 0 <= index <= self.top:
                return self.items[index]
            else:
                print("Invalid index")
                return None

        def reverse(self):
            j = self.top
            i = 0
            while i < j: # 	The loop runs exactly floor(n / 2) times for n elements
                temp = self.array[i] 
                self.array[i] = self.array[j]
                self.array[j] = temp
                i += 1
                j -= 1
            
        def search(self, value):
            index_matches = []
            for i in range(0, self.top + 1):
                if value == self.array[i]:
                    index_matches.append(i)
            return index_matches