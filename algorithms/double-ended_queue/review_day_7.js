/**
 * Review Day 7 for Double-Ended Queue
 * Created on 2025-07-08
 *
 * This is your review exercise for Double-Ended Queue.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Double-Ended Queue
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
class Node {
    constructor(value) {
        this.value = value
        this.next = null
        this.prev = null
    }
}
class DoubleEndedQueue {
    constructor() {
        this.front = null
        this.rear = null
    }
    add_front(value){
        const new_node = new Node(value);
        if (this.front == null) {
            this.front = new_node;
            this.rear = new_node;
        } else {
            // the new node comes before the current front in the linked list, not after it.
            new_node.next = this.front
            this.front.prev = new_node
            this.front = new_node
        }
    }
    add_rear(value){
        const new_node = new Node(value);
        if (this.rear == null) {
            this.rear = new_node;
            this.front = new_node;
        } else {
            new_node.prev = this.rear
            this.rear.next = new_node
            this.rear = new_node
        }
    }
    delete_front(){
    if (this.front === null) {
        console.log("The queue is empty");
        return;
    }

    const deleted = this.front;

    if (this.front === this.rear) {
        // if only one node
        this.front = null;
        this.rear = null;
    } else {
        this.front = this.front.next;
        this.front.prev = null;
    }

    return deleted.value;
    }

    delete_rear() {
    if (this.rear === null) {
        console.log("The queue is empty");
        return;
    }

    const deleted = this.rear.value;

    if (this.rear === this.front) {
        // Only one node in the deque
        this.front = null;
        this.rear = null;
    } else {
        this.rear = this.rear.prev;
        this.rear.next = null;
    }

    return deleted;
    }

    display() {
        let current = this.front;
        const values = [];
        while (current) {
            values.push(current.value);
            current = current.next;
        }
        console.log(values.join(" "));
    }

    display_reverse() {
        let current = this.rear;
        const values = [];
        while (current) {
            values.push(current.value);
            current = current.prev;
        }
        console.log(values.join(" "));
    }
}

const deque = new DoubleEndedQueue();
console.log("Adding elements to the front:");
deque.add_front(10);
deque.add_front(20);
deque.add_front(30);
deque.display(); // Output: 30 20 10

console.log("Adding elements to the rear:");
deque.add_rear(40);
deque.add_rear(50);
deque.add_rear(60);
deque.display(); // Output: 30 20 10 40 50 60

console.log("Deleting elements from the front:");
console.log("Deleted:", deque.delete_front()); // Output: Deleted: 30
console.log("Deleted:", deque.delete_front()); // Output: Deleted: 20
deque.display(); // Output: 10 40 50 60

console.log("Deleting elements from the rear:");
console.log("Deleted:", deque.delete_rear()); // Output: Deleted: 60
console.log("Deleted:", deque.delete_rear()); // Output: Deleted: 50
deque.display(); // Output: 10 40

console.log("Queue in reverse order:");
deque.display_reverse(); // Output: 40 10