/**
 * Review Day 7 for Recursive List Reversal
 * Created on 2025-05-04
 *
 * This is your review exercise for Recursive List Reversal.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Recursive List Reversal
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
function recursive_list_reversal(original_list, index, new_list) {
    if (index < 0) {
        return new_list; //	The base case explicitly returns new_list.
    } else {
        const last_element = original_list[index];
        new_list.push(last_element);
        return recursive_list_reversal(original_list, index - 1, new_list); // 	All earlier calls just pass that same value back up by returning the result of the deeper call. Since the deeper call always eventually reaches the base case and returns new_list, that’s what bubbles back up the entire call stack.
    }
    
}

// Test the implementation
const testData = [5, 2, 9, 1, 5, 6];
const result = recursive_list_reversal(testData, testData.length - 1, []);
console.log(`Result: ${result}`);
