# Array Operations implementation

def array_operations():
    class Array():
        def __init__(self, size):
            self.size = size
            self.length = 0
            self.array = [None] * size

        def insert(self, new_value, index):
            if self.length < self.size:
                for i in range(self.length, index, -1):
                    self.array[i] = self.array[i - 1]
                self.array[index] = new_value
                self.length += 1

        def delete(self, index):
            for i in range(index, self.length - 1):
                self.array[i] = self.array[i + 1]
            self.length -= 1

        
        def display(self):
            if self.length == 0:
                print("Array empty")
            else:
                for i in range(0, self.length):
                    if self.array[i] is None:
                        pass
                    else:
                        print(self.array[i])
