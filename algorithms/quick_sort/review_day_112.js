/**
 * Review Day 112 for Quick Sort
 * Created on 2025-09-07
 *
 * This is your review exercise for Quick Sort.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Quick Sort
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
function quick_sort(items, low = 0, high = items.length - 1) {
    if (low < high) {
        // Partition the array and get pivot index
        const pivotIndex = partition(items, low, high);

        // Recursively sort left and right halves
        quick_sort(items, low, pivotIndex - 1);
        quick_sort(items, pivotIndex + 1, high);
    }
    return items;
}

function partition(items, low, high) {
    const pivot = items[low];
    let i = low + 1;
    let j = high;

    while (true) {
        while (i <= j && items[i] <= pivot) {
            i++;
        }
        while (i <= j && items[j] >= pivot) {
            j--;
        }
        if (i > j) {
            break;
        }
        [items[i], items[j]] = [items[j], items[i]];
    }

    [items[low], items[j]] = [items[j], items[low]];
    return j; 
}


// Test the implementation
const testData = [5, 2, 9, 1, 5, 6];
const result = quick_sort(testData);
console.log(`Result: ${result}`);
