# Insertion Sort
In insertion sort, we assume the very first part of our list is already sorted.  
It includes only one element and one element is by default sorted!

Then we create a loop that goes through each element `i` (after the first element) in the list, and compare it with its predecessors (`j`):

Its predecessor can be one element (if we just got started) or several elements (as we move deeper).

To catch all the comparisons, we need a second loop that starts from `i - 1` (one element before the current `i`) and moves backwards through the sorted part. We use loop because we don’t know how many times we need to move left.

In the second loop, we constantly compare the current `i` to the previous elements.  
If a previous element is bigger than `i`, we shift it to the right.

After we are done shifting (the second loop finishes), we insert the saved value `temp` into the empty spot that was made by all the shifts.

# `j` and `i` Flow Inside Insertion Sort

## Example Scenario
Imagine we have the first part of our list `[3, 8, 2, 1]` sorted and now we are at `2` and we want to insert it into the list.

---

### This is how the while loop flows:

| Step      | `i` (current index) | `j` (compare index) | Action                                           |
|:---------:|:-------------------:|:-------------------:|:-------------------------------------------------|
| Start     | 2                   | 1                   | `temp = arr[2]` (value to insert = 2)             |
| Compare   | 2                   | 1                   | Compare `arr[1] (8)` with `temp (2)` → `8 > 2`    |
| Shift     | 2                   | 1                   | Shift `arr[1]` to `arr[2]` → make space at `arr[1]`; from now on i does not point to the correct place anymore!|
| Move `j`  | 2                   | 0                   | `j -= 1` → move comparison one step to the left  |
| Compare   | 2                   | 0                   | Compare `arr[0] (3)` with `temp (2)` → `3 > 2`    |
| Shift     | 2                   | 0                   | Shift `arr[0]` to `arr[1]` → make space at `arr[0]`  |
| Move `j`  | 2                   | -1                  | `j -= 1` → move comparison one step to the left  |
| Exit loop | 2                   | -1                  | `j == -1` → `j >= 0` fails → exit while loop      |
| Insert    | 2                   | 0 (`j+1`)           | Insert `temp (2)` at `arr[0]`                    |

---

### That's why we insert at `j+1` and not `j`:
> When you exit the loop: arr[j] is smaller than temp (or `j == -1` if we reached start of array). So, the right hole for temp is immediately after `j`, which is `j+1`. After exiting the loop, if we insert at `j` then we have inserted either at -1 which is out of range or we have inserted where we shouldn't have. `j` was smaller, as it was supposed to be!


| Phase                        | What happens                                                    |
|:-----------------------------|:--------------------------------------------------------------:|
| `j >= 0` and `arr[j] > temp`   | Previous element is bigger ➔ Shift it to the right (`arr[j+1] = arr[j]`) and move `j -= 1` |
| `j < 0`                      | Reached the start of the array ➔ No more elements to compare |
| `arr[j] <= temp`              | Found a smaller or equal element ➔ No need to shift anymore |
| After exiting while           | `j` points to a smaller number (or -1) ➔ Insert `temp` at `arr[j + 1]` |
---
### Shift bigger numbers ➔ leave a hole behind ➔ hole is at j + 1 ➔ insert temp there.