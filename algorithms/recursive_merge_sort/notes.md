# Recursive Merge Sort

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