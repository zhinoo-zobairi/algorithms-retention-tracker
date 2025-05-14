# Heap Deletion and Sort Max Heap 
## Skeleton code:
```python
heap = [None, 10, 8, 9, 5, 2]  # 1-based indexing
deleted = []

while heap_size > 0:
    deleted.append(heap[1])
    heap[1] = heap[heap_size]
    heap_size -= 1
    bubble_down() 
````

## What I know about Deletion

Deletion in a **max heap** is not like in a binary search tree where we delete arbitrary nodes. Here, we **only remove from the root**, because that’s the max element. We can’t just delete a leaf because it wouldn’t help us maintain the heap’s structural property.

So what do we do?

- **Step 1:** We remove the root.
- **Step 2:** We take the **last element (bottom-most, right-most)** and **move it to the root**. That creates a bubble that might violate the max heap property.
- **Step 3:** We now have to fix the heap, this is where **heapify-down** comes in:

**we push this replacement element down** by comparing it with its **children below**. If it's smaller than either of its children, it has to move.

And not just randomly; we compare the two children and **swap with the larger one**. That’s how we preserve the rule that the parent is always greater than or equal to its children.

We repeat this process (bubble down) until:
- the element is greater than both children, or
- we’ve reached the bottom of the heap.

At that point, the tree is back to being a valid max heap.

## What I needed to clear up

I had this image of copying the largest child into the parent’s spot and then creating another "bubble" — that’s a fair visual, but more precisely, what happens is:
- we **swap the current element** with its **largest child**, and then continue downward.

Also, in deletion, we're not trying to "find a correct hole" like in insertion; we just **keep pushing the element down** through swaps until it's in a spot that doesn’t violate heap rules.

---

## Heap Sort with Max Heap

Now this part is actually really cool.

If I keep deleting the root of a max heap over and over again — storing each removed element in another array — what I end up with is a **sorted list**.

Because:
- The root is always the largest element.
- Every time I delete, I get the next largest.
- So collecting all those removed roots one after another gives me the elements in **descending order**.

If I reverse that array at the end, I get **ascending order**, which is how we sort using a heap.

This method is known as **Heap Sort**, and it's a great example of how we can use a data structure for more than just storage; here it becomes a **sorting algorithm**.

---

## Final thoughts

The key to understanding deletion in heaps is not just remembering the rules, but **knowing why** the rules are what they are.

- We **insert at the bottom and bubble up** to maintain the max heap.
- We **remove from the top and bubble down** to fix the tree after deletion.
- And we can turn that process into a sorting algorithm if we preserve the removed elements.

This now makes more sense to me because I see deletion as the **mirror image of insertion**, just going the other direction.