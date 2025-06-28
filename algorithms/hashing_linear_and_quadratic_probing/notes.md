# Hashing Linear and Quadratic Probing

## Linear Probing

Linear probing is a collision resolution technique where we search for the next available slot by checking consecutive positions in the hash table.

### How it works:
- When a collision occurs at index `h(key)`, we check `h(key) + 1`, then `h(key) + 2`, etc.
- Formula: `(h(key) + i) % table_size` where `i = 0, 1, 2, 3, ...`
- We continue until we find an empty slot or complete a full cycle

### Example:
```
Table size = 7
Insert key with hash(key) = 3
- Try index 3: occupied → collision
- Try index 4: occupied → collision  
- Try index 5: empty → insert here
```

### Pros:
- Simple to implement
- Good cache performance (sequential access)

### Cons:
- Primary clustering (consecutive occupied slots)
- Performance degrades as table fills up

## Quadratic Probing

Quadratic probing uses a quadratic function to find the next available slot, reducing clustering.

### How it works:
- Formula: `(h(key) + i²) % table_size` where `i = 0, 1, 2, 3, ...`
- Instead of checking consecutive slots, we jump by increasing squares

### Example:
```
Table size = 7
Insert key with hash(key) = 3
- Try index (3 + 0²) % 7 = 3: occupied
- Try index (3 + 1²) % 7 = 4: occupied
- Try index (3 + 2²) % 7 = 0: empty → insert here
```

### Pros:
- Reduces primary clustering
- Better distribution than linear probing

### Cons:
- Secondary clustering (same probe sequence for same hash)
- May not probe all slots (requires table size to be prime)
- More complex than linear probing

## Key Considerations:
- Load factor should be kept below 0.7 for good performance
- Table size should be prime for quadratic probing
- Both methods require the table to have empty slots to guarantee insertion