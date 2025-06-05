/**
 * Review Day 7 for Merge
 * Created on 2025-06-04
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
function merge(items, low, mid, high) {
    let i = low; 
    let j = mid + 1;
    let k = 0;
    let temp = [];
    while (i <= mid && j <= high) {
        if (items[i] <= items[j]) {
            temp[k] = items[i];
            k++;
            i++;
        } else {
            temp[k] = items[j];
            k++;
            j++;
        }
    }
    // Leftovers:
    while (i <= mid) {
        temp[k] = items[i];
        i++;
        k++;
    }
    while (j <= high) {
        temp[k] = items[j];
        j++;
        k++;
    }
    k = 0;
    // let start = low; // would be better to create a new variable to "preserve the boundary", but since we are done with "low" and don't need him hanging around, we can mutate it.
    while (low <= high) {
       items[low] = temp[k]
       k++;
       low++;
    }
    return items;
}

// Test the implementation
const testData = [2, 4, 7, 1, 5, 9];
const result = merge(testData, 0, 2, 5); // Result: 1,2,4,5,7,9
console.log(`Result: ${result}`);
