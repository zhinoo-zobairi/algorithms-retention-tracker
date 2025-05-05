# Binary Heap Insert Operation implementation (Max Heap)

def binary_heap_insert_operation(heap_list, n):
    temp= heap_list[n]
    i = n
    while i > 1 and temp > heap_list[i//2]: # In Python 3, / gives a float. For index calculations, you must use // (integer division).
        heap_list[i] = heap_list[i//2]  # We insert the bigger child in the place of temp
        i = i//2
    
    heap_list[i] = temp # In the last step we insert the hidden temp to the empty space