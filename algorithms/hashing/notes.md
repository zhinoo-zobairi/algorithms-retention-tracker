# Hashing

## Round 1: Foundations

### Q1. What is the purpose of a hash function in a hash table?

The hash function transforms a key (like a string or number) into an array index. That index determines which bucket the data goes into.
In other words, hash function receives an input and produces an output which is the index where we store the input.

## Round 2: Collision Thinking
### Key space can be near-infinite, but storage space is finite.
That's why hashing is not guaranteed one-to-one:
- Multiple keys can map to the same index → called a collision.
- The ideal case is one-to-one (injective), but practically, collisions are inevitable if:
- Key space ≫ table space (pigeonhole principle = If you put n + 1 pigeons into n pigeonholes, at least one pigeonhole has ≥ 2 pigeons.).
- Hash function is imperfect.
### Q2. Let’s say your hash function maps both 25 and 65 to index 5. What do we call this situation, and why does it happen even if the hash function is well-designed?

We want a small, fast-access structure (e.g., array of size 10), not a gigantic array that covers every possible key (e.g., all 32-bit integers).
But this introduces collisions, because many keys must share the same limited set of slots.

## Round 3: Design Choices

### Q3. Now imagine you’re building a hash table. You have to choose between:
- Fixed-size arrays in each bucket, or
- Linked lists in each bucket (chaining).
A linked list in each bucket allows dynamic growth: no need to guess how many collisions will happen at index 5 vs. index 2.

## Round 4: Load Factor Engineering

### Q4. Let’s say your table has 10 buckets and you’ve inserted 20 keys. What is your load factor? And what does a high load factor imply about performance?

`Load Factor = number of elements / number of buckets`

It’s 2, meaning each bucket holds 2 elements on average.

In open addressing, we typically resize (rehash) the table when the load factor exceeds ~0.7.
- You only have 10 slots,
- Yet you’ve inserted 20 elements,
- So your hash table is now overloaded.

In open addressing, a load factor above 1.0 is impossible, because there are no chains — each slot holds at most one element.

A high load factor means:

- More elements are crammed into each bucket,
- Leading to longer chains,
- So lookup time degrades from O(1) to O(n) in the worst case.

## Round 5: Open Addressing vs Chaining

### Q5. Let’s say you don’t want to use linked lists at all. You want to store everything inside the array itself. What’s that technique called and how does it deal with collisions?

1. This is called open addressing
2. You use probing to find the next available slot

#### Probing Techniques:
1.	Linear Probing

Try index + 1, index + 2, … until a free slot is found.

Trade-Off: 

Clustering = when keys clump together in consecutive slots.
You hit an occupied slot → move to next → occupied → next → occupied…

You get longer probe sequences, and average time drifts from O(1) toward O(n).

`h(key) + i  % table_size`

2.	Quadratic Probing

Try jumps of 1², 2², 3², etc.

`h(key) + i²  % table_size`

3.	Double Hashing

Use a second hash function to determine the step size:

`h1(key) + i * h2(key)`

## Round 6: Programming

### A hash table with many slots

Each slot must hold a pointer to the head of a linked list.
	•	Slot 0 → head of list 0
	•	Slot 1 → head of list 1
	•	…
	•	Slot 9 → head of list 9

That means we need an array of Node pointers.

---

In C, an array of Node pointers looks like:
```
struct Node* buffer[10];
````
But this locks the size to 10.
To make it dynamic, we declare it as a pointer to pointer:
```
struct Node** buffer;
````
Buffer itself is a pointer.	Each element in that array is another pointer (struct Node*):
>So type = pointer to pointer.

>struct Node** buffer is address of an array of (struct Node*).

Now buffer points to an array like this:
```
buffer
 ↓
+-----+-----+-----+-----+ ... (capacity times)
|  *  |  *  |  *  |  *  |
+-----+-----+-----+-----+
  |     |     |     |
 NULL  NULL  NULL  NULL
 ```
Each buffer[i] is a struct Node* (head of a list).

### In chaining, each bucket is a linked list: Just think of the bucket as a standalone linked list

> In order to create a chain like `Heads[3] → [5] → [10] → [20] → [30]`, I need to make sure I don’t lose what Heads[3] was already pointing to. That means: before I assign Heads[3] = newNode, I must first save the old value of Heads[3], which is the address of the node holding 10 into newNode->next.
>This way, the new node becomes the new head, and the rest of the chain remains attached. So the insertion is not about blindly assigning the new node to the head, but about shifting the chain forward while keeping the connection to the existing nodes.

>If we want to insert at the end of a bucket’s list instead of at the head, we can’t just blindly assign Heads[index] = newNode.
>We have to traverse the list from Heads[index], follow each ->next, and stop when we find the last node — the one whose next is NULL.
>Then, we simply do:
>lastNode->next = newNode;
>and make sure newNode->next = NULL as well.
