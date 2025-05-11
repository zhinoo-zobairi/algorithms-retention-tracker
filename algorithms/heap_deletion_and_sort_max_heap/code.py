# Heap Deletion and Sort Max Heap implementation

def heap_deletion_and_sort_max_heap(heap):
    
    deleted = heap[1]
    i=1
    
    if heap[2*i] >= heap[2*i + 1]:
        heap[i] = heap[2*i]
    else:
        heap[i] = heap[2*i + 1]
    
def heap_deletion_and_sort_max_heap(heap):
    n = len(heap) - 1  # assuming heap[0] is unused
    sorted_output = []

    while n > 1:
        # Step 1: Save the root (max element)
        deleted = heap[1]
        sorted_output.append(deleted)

        # Step 2: Move last element to root
        heap[1] = heap[n]
        n -= 1        # Reduce the heap size

        # Step 3: Bubble down from root
        i = 1
        while 2 * i <= n: # As long as the current node has at least a left child, keep bubbling down.
            left = 2 * i
            right = 2 * i + 1
            largest = i

            if left <= n and heap[left] > heap[largest]:
                largest = left
            if right <= n and heap[right] > heap[largest]:
                largest = right

            if largest == i:
                break
            else:
                heap[i], heap[largest] = heap[largest], heap[i]
                i = largest

    return sorted_output
