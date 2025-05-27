/**
 * Review Day 7 for Quick Sort
 * Created on 2025-05-25
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
/**
function swap(a, b) { JavaScript passes primitives by value, so a and b inside swap(a, b) are just copies of the original values. Changing a = temp only changes the copy, not the original array.
    let temp = a;
    b = a;
    a = temp;
}
    */
function swap(arr, i, j) {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


function partition(items, l, h) {
    const pivot = items[l];
    let i= l+1;
    let j = h;
    while (i<=j) {
        while(items[i] < pivot) 
            i++;
        while (items[j] > pivot) 
            j--;
        if (i < j) {
        swap(items, i, j);
        i++;
        j--;
    } else {
        break;}
    }
    swap(items, l, j);
    return j;
}

function quick_sort(items, low = 0, high = items.length - 1) {
    if (low < high) {
        const p = partition(items, low, high);
        quick_sort(items, low, p - 1);
        quick_sort(items, p + 1, high);
    }
    return items;
}

// Test the implementation
const testData = [5, 2, 9, 1, 5, 6];
const result = quick_sort(testData);
console.log(`Result: ${result}`);
