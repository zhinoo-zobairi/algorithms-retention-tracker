# Counting Sort

## Core Idea

**Goal**: Sort an array of non-negative integers in linear time  
**Key Principle**: Use a helper array to count how many times each value occurs.

---

## Step 1: Find the Maximum Value

Before anything else, scan the input array to find the **maximum value** — let's call it `max_val`.

We do this because the counting array needs one slot for **every value from `0` up to `max_val`**, so its size must be `max_val + 1`.

> **Example**:  
> Input array: `[4, 2, 2, 8, 3, 3, 1]`  
> → `max_val = 8`  
> → Allocate `count = [0] * 9`  (indices `0` to `8`)

---

## Step 2: Count Frequencies

Create a **count array** of size `max_val + 1`, initialized to all zeros.

Then loop over each element `num` in the original array and do:

```python
count[num] += 1
```
Now, `count[i]` tells you how many times the number i appears in the input array.

> Think of this as building a histogram of the values.

## Step 3: Reconstruct the Sorted Array

Now overwrite the original array with sorted values using the count array.

Start with a pointer pos = 0 on the input array.

Loop through `i` from 0 to max_val:
```python
while count[i] > 0:
    arr[pos] = i
    pos += 1
    count[i] -= 1
```
Each i will be written count[i] times into the array, so the result is sorted.

### Recap: Mental Model
- Use the value itself as an index in the helper array.
- Count how many times each value appears.
- Reconstruct the sorted list by writing each value its counted number of times.

## Time & Space Complexity

| Aspect        | Complexity                     |
|---------------|-------------------------------|
| Time          | O(n + k): `n` is the number of elements, `k` is the max value |
| Space         | O(k): auxiliary array of size `max_val + 1` |
| Stable?       | Not stable by default (can be made stable with prefix sums) |
| In-place?     | No, requires extra space for counting array |

---

## When Not to Use Counting Sort

- Input contains **negative numbers**  
  Counting Sort doesn't handle negatives unless adapted manually.
  
- The **range of values is too large**  
  For example, sorting `[3, 1000000, 4]` would require a counting array of length 1,000,001 → inefficient!

- You need a **stable sort**  
  The basic version of Counting Sort is not stable (doesn’t preserve original order of equal elements).

> Only use Counting Sort when:
> - You’re sorting **non-negative integers**
> - The **range is small**
> - You care about **speed over memory**