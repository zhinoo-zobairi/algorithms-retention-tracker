from merge.code import merge

def iterative_merge_sort(items):

    size = 1

    while size < len(items): # from size = 1 onwards, we grab it and calculate low, mid and high for them

        for start in range(0, len(items), 2*size):

            low = start

            mid = min(start+size - 1, len(items)-1)

            high = min(start+2*size -1, len(items)-1)

            left_half = items[low:mid+1]

            right_half = items[mid+1:high+1]

            merged = merge(left_half, right_half)

            items[start:high+1] = merged # because our merge is not in-place and returns a new array, we have to manually copy it back into the original array.
            # In slicing the start index is inclusive. The end index is exclusive, hence the + 1
            
        size *=2