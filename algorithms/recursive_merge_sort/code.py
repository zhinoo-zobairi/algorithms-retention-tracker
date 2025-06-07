# Recursive Merge Sort implementation
from merge.code import merge # As merge/code.py and recursive_merge_sort/code.py are in sibling folders

"""
RECURSIVE MERGE SORT EXPLANATION:

This implementation uses the classic "divide and conquer" approach:

1. DIVIDE: Split the array into two halves at the midpoint
2. CONQUER: Recursively sort both halves (base case: single elements are already sorted)
3. COMBINE: Merge the two sorted halves back together using the merge function

WHY IT WORKS:
- Base case: Arrays of size 1 are already sorted
- Recursive case: If we can sort smaller arrays, we can sort larger ones by merging
- Time complexity: O(n log n) - we divide log n times, merge takes O(n) each time
- Space complexity: O(n) - for the temporary arrays during merging

The key insight: sorting two smaller sorted arrays is easier than sorting one large unsorted array.
"""


def recursive_merge_sort(items, l, h):
    if l < h:
        mid = (l + h) // 2
        recursive_merge_sort(items, l, mid)
        recursive_merge_sort(items, mid + 1, h)
        left_part = items[l:mid+1]
        right_part = items[mid+1:h+1]
        merged = merge(left_part, right_part)

        # Copy the merged result back to the original array
        for i in range(len(merged)):
            items[l + i] = merged[i]

# the caller provides l and h manually:
items = [38, 27, 43, 3, 9, 82, 10]
recursive_merge_sort(items, 0, len(items) - 1)
print(f"Sorted: {items}")


