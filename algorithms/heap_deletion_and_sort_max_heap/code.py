# Heap Deletion and Sort Max Heap implementation

def heap_deletion_and_sort_max_heap(items):
    
    deleted_elements = [] # We store deleted root values here to produce a sorted list
    
    heap_current_length = len(items) - 1 # Calculate how many actual elements are in the heap (excluding dummy at index 0)

    
    while heap_current_length > 0: # While there's still at least one element to delete (the root), keep going

        deleted_element = items[1] # Saving the root, so that we can access it later
        
        items[1] = items[heap_current_length] # We drop the last guy into the king’s throne. That’s a broken hierarchy. So we need to restore order soon...

        heap_current_length -= 1 # Shrink the heap size; because we track it above in the while's start

        deleted_elements.append(deleted_element) # Record the deleted root value, so that we can have a sorted list later

        i = 1 # What I've been waiting for: Start bubbling down from the root and restoring hierarchy

        while 2 * i <= heap_current_length: # While current node has at least a left child
            
            left = 2 * i

            if 2 * i + 1 <= heap_current_length: # Case 1: Right child exists AUCH!

                right = 2 * i + 1

                if items[left] > items[right] and items[left] > items[i]:
                    temp = items[i]  # Swap with left child
                    items[i] = items[left]
                    items[left] = temp
                    i = left # We change the place of the last guy we dropped in the king's throne to be able to continue comparing

                elif items[right] > items[i]: # Swap with right child
                    temp = items[i]
                    items[i] = items[right]
                    items[right] = temp
                    i = right # We change the place of the last guy we dropped in the king's throne to be able to continue comparing

                else:

                    break  # No need to swap: HEAP ALREADY VALID


            else: # Case 2: Only left child exists

                if items[left] > items[i]: # We only compare that single child with the parent, if it's bigger, then swap; if not just break and go home.
                    temp = items[i]
                    items[i] = items[left]
                    items[left] = temp
                    i = left
                else:
                    break
    
    return deleted_elements # Return all the deleted root values, which are in descending order


