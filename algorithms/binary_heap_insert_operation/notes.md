# Binary Heap Insert Operation

## I will be implementing a Max Heap here and we'll see how we handle insertion in such complete binary tree.

### First things first, Q: what does Max Heap mean?
> The very root element is the biggest element.
 
### Q: Where are we allowed to insert?
> Since it is a complete binary tree, we are only allowed to insert at the **leftmost available position on the lowest level**.
> If the parent is smaller, we move the parent **down** and form a bubble in its place, continue moving **up** the tree until we find the right position for the new element.


### Q: What next then?
> > To maintain the Max Heap property, we need to compare the newly inserted element (the **youngest child**) with its parent.

### ⛔️ Bubbling up (sift-up): Just rememeber there is a bubble traveling towards the root and we wait until we are done comparing the temp with each parent and we insert the temp at very last step in the bubble. So, Instead of swapping at every step, we keep moving parents down until we reach the right spot, then we place the new element there.

*So just to be on the safe side, I repeat again:*

### This is the “hole-copying” method, which is one of two typical approaches:
- One is bubble-up with swaps (swap the new element with the parent repeatedly).
- The other is hole-shifting (you move the parent down until the right spot is found for the new value).
