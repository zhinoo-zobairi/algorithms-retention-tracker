/**
 * Review Day 7 for Binary Heap Insert Operation
 * Created on 2025-05-12
 *
 * This is your review exercise for Binary Heap Insert Operation.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Binary Heap Insert Operation
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
function binary_heap_insert_operation(items, new_element) {
    let i = items.length;
    while (i > 1 && new_element > items[Math.floor(i / 2)]) {
        items[i] = items[Math.floor(i / 2)];  // Moving parent down to the hole
        i = Math.floor(i / 2);               // Moving the hole up to the parent
    }
    items[i] = new_element;
    return items;
}

// Test the implementation
const testData = [5, 2, 9, 1, 5, 6];
const result = binary_heap_insert_operation(testData);
console.log(`Result: ${result}`);
