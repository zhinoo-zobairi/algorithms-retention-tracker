/**
 * Review Day 112 for Insertion Sort
 * Created on 2025-08-16
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
     for (let index = 1; index < items.length; index++) {
        const temp = items[index];
        let j = index -1;
        while (j >= 0 && items[j] > temp) {
            items[j+1] = items[j];
            j = j - 1;
        }
        items[j+1] = temp;
     }
    return items;
}

const testData = [5, 2, 9, 1, 5, 6];
const result = insertion_sort(testData);
console.log(`Result: ${result}`);
