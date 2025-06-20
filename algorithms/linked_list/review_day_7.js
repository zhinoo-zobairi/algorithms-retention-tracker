/**
 * Review Day 7 for Linked List
 * Created on 2025-06-18
 *
 * This is your review exercise for Linked List.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Linked List
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}
let head = null;
let prev = null;
function createLinkedListFromArray(array) {
    for (let index = 0; index < array.length; index++) {
        if (index == 0) {
            const node_1 = new Node(array[index]);
            head = node_1;
            prev = node_1;
        } else {
            const new_node = new Node(array[index]);
            prev.next = new_node;
            prev = new_node;
        }

        
    }
    return head;
}

function printLinkedList(head) {
    let node = head;
    while (node != null ) {
        console.log(node.value);
        node = node.next;
    }
}

const testData = [5, 2, 9, 1, 5, 6];
head = createLinkedListFromArray(testData);
printLinkedList(head)
