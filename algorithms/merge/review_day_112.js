/**
 * Review Day 112 for Merge
 * Created on 2025-09-17
 *
 * This is your review exercise for Merge.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Merge
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
// This is not in-place:
function merge(items_1, items_2) {
    let i = 0;
    let j = 0;
    let mixed_items = [];
    let k = 0;
    while (i < items_1.length && j < items_2.length) {
        if (items_1[i] >= items_2[j]) {
            mixed_items[k] = items_2[j];
            j++;
        } else{
            mixed_items[k] = items_1[i];
            i++;
        }
        k++;
    }
    if (i < items_1.length) {
        while (i < items_1.length) {
            mixed_items[k] = items_1[i];
            i++;
            k++;
        }
    }
    if (j < items_2.length) {
        while (j < items_2.length) {
            mixed_items[k] = items_2[j];
            j++;
            k++;
        }
    }
    return mixed_items;
}

// Test the implementation
const testData_1 = [1, 2, 10];
const testData_2 = [7, 9, 11, 20];

const result = merge(testData_1, testData_2);
console.log(`Result: ${result}`);
