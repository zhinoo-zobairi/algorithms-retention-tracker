# Merge

## Merging Two Sorted Arrays

Merging means combining two **sorted lists** into one sorted result.

We use two pointers:
- One for each input list.
- At each step, compare the current elements.
- Append the smaller one to the result, which is an auxiliary array and move that exact pointer.

When one list is exhausted, we append the rest of the other list (since it’s already sorted).

⚠️ Needs extra space: we build a new list for the result, an auxiliary array, which is a helper array you create on the side to store intermediate results, track extra info, or simplify the logic: like a “scratchpad” during the computation.

Used in:
- Merge sort
- Merging logs or timelines
- External sorting