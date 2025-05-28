# Review Day 14 for Heap Deletion and Sort Max Heap
# Created on 2025-05-25

'''
This is your review exercise for Heap Deletion and Sort Max Heap.
Complete the implementation below to reinforce your understanding.
'''

def heap_deletion_and_sort_max_heap(items):
    """
    Implementation of Heap Deletion and Sort Max Heap
    
    TODO: Implement the algorithm from memory to reinforce your learning
    """
    resulted_sorted_list = []
    length = len(items) - 1 # because items[0] = None (placeholder)

    while length > 1:
        i = 1
        deleted = items[i]
        items[i] = items[length]
        while 2*i <= length:
            left_child = 2*i
            right_child = 2*i + 1
            larger_child = left_child
            if right_child <= length and items[right_child] > items[left_child]:
                larger_child = right_child
            if items[larger_child] > items[i]:
                items[i], items[larger_child] = items[larger_child], items[i] # copying the value from larger_child into the i-th position and putting the newly added root from i-th position in the place of larger child
                i = larger_child
            else:
                break
        
        resulted_sorted_list.append(deleted)
        length -= 1 
        # Manually tracked `length` ensures clean bounds. No access to stale tail elements.
    resulted_sorted_list.reverse()
    return resulted_sorted_list

# The heap must be a max heap
if __name__ == "__main__":
    test_data = [None, 9, 5, 6, 2, 5, 1]
    result = heap_deletion_and_sort_max_heap(test_data)
    print(f"Result: {result}")

