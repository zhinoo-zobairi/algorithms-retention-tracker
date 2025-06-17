/**
 * Review Day 7 for Counting Sort
 * Created on 2025-06-15
 *
 * This is your review exercise for Counting Sort.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Counting Sort
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
function counting_sort(items) {
    if (items.length === 0) return items;
    const max = Math.max(...items); // The ...items spreads the array into individual arguments, that's how Math.max works: expects comma-separated arguments, not an array.
    const aux = new Array(max + 1).fill(0);
    for (let i = 0; i < items.length; i++) {
        aux[items[i]] ++; 
    }
    let k = 0;
    for (let j = 0; j < aux.length; j++) {
        while (aux[j] > 0) {
        items[k] = j;
        aux[j]--;
        k++;
        }
    }  
    return items;
}

// Test the implementation
const testData = [5, 2, 9, 1, 5, 6];
const result = counting_sort(testData);
console.log(`Result: ${result}`);
