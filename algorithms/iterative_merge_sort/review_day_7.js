const { merge } = require('../merge/review_day_7');
console.log("merge() function imported");
/**
 * Review Day 7 for Iterative Merge Sort
 * Created on 2025-06-06
 *
 * This is your review exercise for Iterative Merge Sort.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Iterative Merge Sort
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
function iterative_merge_sort(array) {
    for (let size = 1; size < array.length; size *= 2) {
        for (let start = 0; start < array.length; start += 2*size) {
            let mid = Math.min(start + size - 1, array.length - 1);
            let high = Math.min(start + 2 * size - 1, array.length - 1);
            if (mid < high) { // Do not merge if there's only one subarray
                merge(array, start, mid, high);
            }
            
        } 
    }
    return array;
}

// Test the implementation
const testData = [5, 2, 9, 1, 5, 6];
const result = iterative_merge_sort(testData);
console.log(`Result: ${result}`);
