# Review Day 14 for Quick Sort
# Created on 2025-06-01

'''
This is your review exercise for Quick Sort.
Complete the implementation below to reinforce your understanding.
'''

def partition(items, l, h):
    pivot = items[l]
    i = l+1
    j = h

    while True:
        while i <= h and items[i] < pivot:
            i += 1
        while j >= l and items[j] > pivot:
            j -= 1
        if i < j:
            items[i], items[j] = items[j], items[i]
        else: # because if i and j meet at the very end of the array, then we have no other option other than to swap
            items[l], items[j] = items[j], items[l] # I initially made a mistake here: I wrote pivot instead of items[l], which won't result in modifying the array
            return j
        
        
def quick_sort(items, l, h):
    if l >= h:
        return 
    j = partition(items, l, h)
    quick_sort(items, l, j-1)
    quick_sort(items, j + 1, h)

if __name__ == "__main__":
    test_data = [5, 2, 9, 1, 5, 6]
    quick_sort(test_data, 0, len(test_data) - 1)
    print(f"Result: {test_data}")
