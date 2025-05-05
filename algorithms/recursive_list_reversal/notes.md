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

---

# C Implementation Notes

## Important Differences Between Python and C

- Negative indexing does not exist in C! You must manually access the last element using `arr[size - 1]`.
- In Python, when we do something like `lst[:-1]`, Python internally allocates memory for the new list. You never worry about where in RAM the new list lives.
- C has no slicing like Python!
- In C, arrays are fixed when created: no more, no less.
- There is no built-in way to say "give me a new array without the last element."
- If you want a smaller array, you must manually create a new one using dynamic memory allocation.
> Hence, we don't use this strategy in C. Creating a new smaller array each time would require manually allocating memory with `malloc`, copying elements over, and then eventually freeing that memory with `free`. This process would be unnecessarily complex, error-prone, and inefficient for simple operations like reversing a list. Therefore, in C, it is much simpler and safer to swap elements in-place using existing arrays.
### Memory?

- Stack: where static memory (like `int arr[10];`) lives. For variables that have a short, predictable lifetime (e.g., function variables). You know at compile time how big the thing is. Stack memory is usually small (like 1–8 MB). If you tried to create something huge (like an array of 10 million integers) on the stack, you would crash the program with a stack overflow.

- Heap: for dynamic memory (created at runtime using `malloc`). For variables/objects that need to live longer, flexible size, dynamic creation. You need flexibility at runtime (dynamic sizing)


## Heap vs Stack in C

| Concept | Stack | Heap |
|:--------|:------|:-----|
| Memory Allocation | Happens automatically for static arrays and local variables | Happens manually using `malloc()` |
| Managed by | Compiler | Programmer |
| Lifetime | Until function ends (automatic cleanup) | Until manually freed with `free()` |
| Access Speed | Very fast | Slower compared to stack |
| Example | `int arr[10];` | `int *arr = (int *)malloc(10 * sizeof(int));` |


### Example:

```c
int n;
scanf("%d", &n); // User inputs size at runtime
int *arr = (int *)malloc(n * sizeof(int));
```

Here, the program asks the user for a size and allocates an array dynamically while running.

---

# Java Implementation Notes
## Instance vs. Static Method — The "Laptop" Analogy

When working with `this.result` vs. passing inputs, think of it like **company vs. student laptops**.

| Situation                        | Instance Method (`this.result`)                                  | Static Method (passing result as argument)                  |
|---------------------------------|------------------------------------------------------------------|-------------------------------------------------------------|
| **Analogy**                     | Company gives you a laptop                                    | You bring your own laptop every day                      |
| **Who owns the result list?**   | The object ("Jînno" → `this.result`)                            | You, the caller, pass it in and take it back (return value) |
| **Memory persistence**          | Stays with the object across method calls                       | Must be passed in and returned every time                   |
| **Example**                     | `result.add(...)` uses the instance’s memory                    | `result.add(...)` uses the caller’s list                    |
| **Code Example**                | `public void reverse_helper(...) { result.add(...); }`          | `public static List<Integer> reverse(...) { ... return result; }` |
| **Returning data**              | Often no need to return → data stays in the object              | Must return the result list to keep track of changes        |

---

### Why?

- **Instance method** → You already have a storage (company laptop). No need to "carry" results.
- **Static method** → Every time, you must *bring* your data in and *take* it back out.

---
