# Review Day 14 for Binary Heap Insert Operation
# Created on 2025-05-19

'''
This is your review exercise for Binary Heap Insert Operation.
Complete the implementation below to reinforce your understanding.
This fully handles insertion (add + bubble up)
'''

def binary_heap_insert_operation(items, x):
    n = len(items)
    items.append(x) # Cannot do items[n+1] = x, Python does NOT allow this if items doesn’t already have that index. "append()" grows the list and places x at the next available slot 
    while n > 1 and items[n//2] < x:
        items[n] = items[n//2]
        n = n//2
    items[n] = x

if __name__ == "__main__":
    test_data = [5, 2, 9, 1, 5, 6]
    result = binary_heap_insert_operation(test_data)
    print(f"Result: {result}")
