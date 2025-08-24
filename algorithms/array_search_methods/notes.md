# Array Search Methods

Array search methods are techniques used to locate a specific value within an array. The two most common methods are linear search and binary search.

## Linear Search
Linear search examines each element in the array sequentially until the target value is found or the end of the array is reached. It works on both sorted and unsorted arrays, but can be inefficient for large datasets.

### Improvements to Linear Search
- **Transposition:** When a target element is found, it is swapped with the element just before it. This way, frequently accessed elements gradually move closer to the front, improving average search time for repeated searches.
- **Move-to-Front (or Move-to-Head):** When a target element is found, it is moved directly to the front (head) of the array. This is especially effective if certain elements are searched for more often, as it reduces the time to find them in future searches.

## Binary Search
Binary search is a much faster method but requires the array to be sorted. It works by repeatedly dividing the search interval in half and comparing the target value to the middle element. This method is highly efficient for large, sorted arrays.

## Time Complexity Analysis

### Linear Search
- **Best Case:** O(1) (target is at the first position)
- **Average Case:** O(n) (target is somewhere in the middle or not present)
- **Worst Case:** O(n) (target is at the last position or not present)

### Binary Search
- **Best Case:** O(1) (target is at the middle position on the first check)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

Here, n is the number of elements in the array. Binary search is much more efficient for large, sorted arrays, while linear search is more flexible but slower for large datasets.

### Key Points
- Linear search is simple and works on any array, but can be slow for large datasets.
- Binary search is efficient but only works on sorted arrays.
- Improvements like transposition and move-to-front can make linear search more efficient when some elements are accessed more frequently than others.