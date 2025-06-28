# Hashing Linear and Quadratic Probing implementation

class hash_table:
    def __init__(self, size):
        self.size = size
        self.hash_table = [None] * size

    def linear_probing(self, index):
        i = 0
        while i < self.size:
            if self.hash_table[index + i] is None:
                return i
            i += 1;
        return - 1 # Table is full
    def quadratic_probing(self, index):
        i = 0
        while i < self.size:
            probe_index = (index + i * i) % self.size  # i² instead of i
            if self.hash_table[probe_index] is None:
                return probe_index
            i += 1
        return -1

    def insert(self, key):
        index = key % self.size
        if self.hash_table[index] is None:
            self.hash_table[index] = key
        else:
            probe_index = self.linear_probing(index)
            if probe_index != -1:
                self.hash_table[probe_index] = key
            else:
                print("Hash table is full")
    
    def display(self):
        print(f"Hash table: {self.hash_table}")


ht = hash_table(8)
ht.insert(10)
ht.insert(17)
ht.insert(27)
ht.display()