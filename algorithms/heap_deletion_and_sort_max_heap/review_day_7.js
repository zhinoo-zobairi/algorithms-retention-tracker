/**
 * Review Day 7 for Heap Deletion and Sort Max Heap
 * Created on 2025-05-18
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
function heap_deletion_and_sort_max_heap(items) {
   let heapLength = items.length;
   let deletedElements = [];
   while (heapLength > 0) {
    
        const deleted = items[0];
        items[0] = items[heapLength - 1];
        heapLength--;
        deletedElements.push(deleted);
        let i = 0;
        while (2 * i + 1 <= heapLength - 1) {
            let left = 2 * i + 1;
            let right = 2 * i + 2;
            let largerChild;
            if (right <= heapLength - 1 && items[right] > items[left]) {
                largerChild = right;            
            } else {
                largerChild = left;
            }
            if (items[largerChild] > items[i]) {
                let temp = items[i];
                items[i] = items[largerChild];
                items[largerChild] = temp;
                i=largerChild;
            
            } else {
                break;
            }
        }
    }
    return deletedElements.reverse();
    }

//You’re expected to pass a valid max-heap. The constructor will not validate or build it for you.
const testData = [9, 5, 6, 1, 2, 5];
const result = heap_deletion_and_sort_max_heap(testData);
console.log(`Result: ${result}`);

//Right now, I am: Mutating items during heapify but using a separate deletedElements[] array for the result: O(n)
//In-place heap sort = sort using only the input array: O(1)


