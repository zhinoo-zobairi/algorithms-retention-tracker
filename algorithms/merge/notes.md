# Merge

## Merging Two Sorted Arrays

Merging means combining two **sorted lists** into one sorted result.

We use two pointers:
- One for each input list.
- At each step, compare the current elements.
- Append the smaller one to the result and move that pointer.

When one list is exhausted, we append the rest of the other list (since it’s already sorted).

⚠️ Needs extra space: we build a new list for the result.

Used in:
- Merge sort
- Merging logs or timelines
- External sorting