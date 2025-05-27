# Quick Sort
## Hoare Partition Scheme

| Step | What Happens | Correct? | Commentary |
|------|--------------|----------|------------|
| 1 | `i` increments while `A[i] <= pivot` | Yes | Looks for the first element too big on the left. Moves right, skipping all elements that are correctly less than or equal to pivot |
| 2️ | `j` decrements while `A[j] > pivot` | Yes | Looks for the first element too small on the right. Moves left, skipping all elements that are correctly greater than the pivot |
| 3️ | If `i < j`, then swap `A[i]` and `A[j]` | Yes | These two are on the wrong side and must be exchanged |
| 4️ | Repeat while `i < j` | Yes | Keep going until pointers meet or cross: that’s your **partition boundary** |
| 5️ | Once `i >= j`, exit the loop and swap pivot with `A[j]` | Yes | This places the pivot into its correct region (left ≤ pivot, right > pivot) |

quick_sort([5, 2, 9, 1, 5, 6], 0, 5)
│
├── partition(...) → returns p = 2
│
├── quick_sort(..., 0, 1)   ← handles left half
│   └── partition(...) → returns new p
│   └── quick_sort(..., ...) (left half of left)
│   └── quick_sort(..., ...) (right half of left)
│
└── quick_sort(..., 3, 5)   ← handles right half
    └── partition(...) → returns new p
    └── quick_sort(..., ...) (left half of right)
    └── quick_sort(..., ...) (right half of right)