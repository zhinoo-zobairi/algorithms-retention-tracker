/**
 * Review Day 112 for Counting Sort
 * Created on 2025-09-28
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
function find_max(items) {
    let biggest = items[0];
    for (let i = 0; i < items.length; i++) {
        if (items[i] > biggest) {
            biggest = items[i];
        }
    }
    return biggest;
}
function counting_sort(items) {
    if (items.length === 0) return items;
    const maximum_element = find_max(items);
    let aux_arr = [];
    for (let i = 0; i <= maximum_element; i ++) {
        aux_arr[i] = 0;
    }
    for (let i = 0; i < items.length; i ++) {
        aux_arr[items[i]] += 1; 
    }
    let j = 0;
    for (let i = 0; i <= maximum_element; i ++) {
        while (aux_arr[i] !== 0) {
            items[j] = i;
            aux_arr[i] --;
            j++;
        }
    }
    return items;
}

// Test the implementation
const testData = [5, 2, 9, 1, 5, 6];
const result = counting_sort(testData);
console.log(`Result: ${result}`);
