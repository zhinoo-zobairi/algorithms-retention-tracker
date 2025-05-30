# Iterative Merge Sort implementation
from merge.code import merge
def iterative_merge_sort(items):
    size = 1
    while size < len(items): # the last useful merge happens when the length of the sublists are in fact less than the original list's length; hence < and not <=
        for start in range(0, len(items), 2*size):
            mid = start + size - 1
            end = min(mid + size, len(items) - 1) # When handling the last chunk in a list with uneven size, we may walk past the borders if we don't catch it
            first_half = items[start:mid+1]
            second_half = items[mid+1:end+1]
            merged = merge(first_half, second_half)
            items[start:end+1] = merged  # OVERWRITE the sorted chunk
        size *=2

if __name__ == "__main__":
    items = [38, 27, 43, 3, 9, 82, 10, 5]
    iterative_merge_sort(items)
    print(items)