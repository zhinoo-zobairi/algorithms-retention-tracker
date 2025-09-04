/**
 * Review Day 112 for Heap Deletion and Sort Max Heap
 * Created on 2025-08-31
 *
 * This is your review exercise for Heap Deletion and Sort Max Heap.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Heap Deletion and Sort Max Heap
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
function heap_deletion(items) {
    if (items.length === 0) {
        return;
    }
    if (items.length === 1) {
        const only = items[0];
        items.pop()
        return only;
    }
    const deleted = items[0];
    let index = 0;
    const last = items.pop()
    items[0] = last;
    while ((2 * index) + 1 < items.length ) {
        const left_index = (2 * index) + 1;
        const right_index = (2 * index) + 2;
        let bigger_index = left_index;
        if (right_index < items.length && items[right_index] > items[left_index]) {
        bigger_index = right_index;
        }
        if (items[index] < items[bigger_index]) {
        const temp = items[index];
        items[index] = items[bigger_index];
        items[bigger_index] = temp;
        index = bigger_index;
        }
        else{
            break;
        }
    }
    return deleted;
}
function heap_sort(items) {     //Side effect: heap_sort empties the input array.
    let deletedElements = [];
    while (items.length > 0) {
        deletedElements.push(heap_deletion(items));
    }
    return deletedElements.reverse()
}

// Pass in heap
const testData = [30, 20, 25, 10, 15, 9, 8];
const result = heap_sort(testData);
console.log(`Result: ${result}`);
