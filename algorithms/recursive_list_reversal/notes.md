# Recursive List Reversal

# Problem Statement

Implement a recursive function list_reverse(l) that:

Returns a new list with the elements reversed,

Does not modify the original list,

Does not use forbidden functions like reversed, sorted, input, etc.
--- 
# My Approach

I decided to cut off the last element at each step.

Take the last element (lst[-1]),

Recursively reverse the rest (lst[:-1]),

Put the last element in front of the reversed rest.

## Base Case

If the list has 0 or 1 element, it is already reversed.

**Return it directly.**