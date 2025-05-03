/**
 * Review Day 7 for Insertion Sort
 * Created on 2025-05-03
 *
 * This is your review exercise for Insertion Sort.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Insertion Sort
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
function insertion_sort(items) {
    for (let i = 1; i < items.length; i++) {
        const key = items[i];
        let j = i-1;
        while (items[j]>key && j>= 0) {
            items[j+1] = items[j];
            j= j-1;
        }
        items[j+1] = key;
    }
    return items;
}

// Test the implementation
const testData = [5, 2, 9, 1, 5, 6];
const result = insertion_sort(testData);
console.log(`Result: ${result}`);
