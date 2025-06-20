# Review Day 14 for Recursive Merge Sort
# Created on 2025-06-20

'''
This is your review exercise for Recursive Merge Sort.
Complete the implementation below to reinforce your understanding.
'''
from merge.code import merge

def recursive_merge_sort(items, l, h):
    """
    Implementation of Recursive Merge Sort
    
    TODO: Implement the algorithm from memory to reinforce your learning
    """
    if l < h:
        mid = (l + h) // 2
        recursive_merge_sort(items, l, mid)
        recursive_merge_sort(items, mid+1, h)
        left_part = items[l:mid+1]
        right_part = items[mid+1:h+1]
        result = merge(left_part, right_part)

        for i in range(len(result)):
            items[l + i] = result[i]



if __name__ == "__main__":
    test_data = [5, 2, 9, 1, 5, 6]
    recursive_merge_sort(test_data, 0, 5)
    print(f"Result: {test_data}")

# From the 'algorithms' directory, run: python -m recursive_merge_sort.review_day_14

