# Iterative Merge Sort implementation
from merge.code import merge

"""
HOW TO RUN THIS FILE:

METHOD 1 (Recommended): Use module execution
From the 'algorithms' directory, run:
    python -m iterative_merge_sort.code

METHOD 2: Add sys.path fix for direct execution  
If you want to run directly with: python iterative_merge_sort/code.py
You need to add this BEFORE the import:
    import sys, os
    sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

WHY THE DIFFERENCE:
- Both files import from sibling directory: 'from merge.code import merge'
- Python's module resolution depends on the current working directory
- Module execution (-m) preserves the algorithms/ working directory
- Direct execution changes working directory to the script's location
- This affects where Python looks for the 'merge' module

"""

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

if __name__ == "__main__": #  That’s my execution guard. When I run this file directly with python iterative_merge_sort/code.py, the print(items) will execute; But when I import it from another file: from iterative_merge_sort.code import iterative_merge_sort. then __name__ != "__main__" so the test does not run 
    items = [38, 27, 43, 3, 9, 82, 10, 5]
    iterative_merge_sort(items)
    print(items)