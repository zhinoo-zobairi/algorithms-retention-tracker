/**
 * Review Day 7 for Queue
 * Created on 2025-07-06
 *
 * This is your review exercise for Queue.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Queue
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
class ArrayQueue {
    constructor(capacity) {
        this.size = 0;
        this.rear = -1;
        this.front = -1;
        this.capacity = capacity;
        this.array = new Array(capacity);
    }
    enqueue(item){
        if (this.capacity == this.size) {
            console.log("Queue is full");
        } else {
        this.rear++;
        this.array[this.rear] = item;
        this.size++;  
        }
    }
    dequeue(){
        if (this.rear == -1) {
            console.log("Queue is empty");
        } else {
            this.front++;
            const deleted = this.array[this.front];
            this.size--;
            if (this.size === 0) {
            this.front = -1;
            this.rear = -1;
            }
        return deleted;
        }
    }
    display(){
        if (this.size == 0) {
            console.log("Queue is empty");
        } else {
            let i = this.front + 1; // We don't want to alter the pointer itself
            while (i <= this.rear) {
                console.log(this.array[i]);
                i++;
            }
        }
    }
}

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}
class LinkedListQueue {
    constructor() {
        this.front = null
        this.rear = null
    }
    enqueue(value){
        const new_node = new Node(value)
        if (this.rear == null) {
           this.front = new_node
           this.rear = new_node
        } else {
            this.rear.next = new_node
            this.rear = new_node
        }
    }
    dequeue(){
        if (this.rear == null) {
            console.log("Queue is empty");
        } else {
            const deleted = this.front.data
            this.front = this.front.next
            if (this.front === null) { // if we only have one element → front === rear, we have to update rear also, because rear points to the old node still
            this.rear = null
            }
            return deleted
        }
    }
    display(){
        if (this.rear == null) {
            console.log("Queue is empty");
        } else {
            let current = this.front;
            while (current != null) {
                console.log(`Data is ${current.data}`);
                current = current.next
            }
        }
    }
}

// Testing ArrayQueue
console.log("Testing ArrayQueue:");
const arrayQueue = new ArrayQueue(3);
arrayQueue.enqueue(10);
arrayQueue.enqueue(20);
arrayQueue.enqueue(30);
arrayQueue.display(); // Output: 10, 20, 30
console.log("Dequeued:", arrayQueue.dequeue()); // Output: 10
arrayQueue.display(); // Output: 20, 30
arrayQueue.enqueue(40); // Should work since there's space
arrayQueue.display(); // Output: 20, 30, 40
arrayQueue.enqueue(50); // Should log "Queue is full"

// Testing LinkedListQueue
console.log("\nTesting LinkedListQueue:");
const linkedListQueue = new LinkedListQueue();
linkedListQueue.enqueue(100);
linkedListQueue.enqueue(200);
linkedListQueue.enqueue(300);
linkedListQueue.display(); // Output: Data is 100, Data is 200, Data is 300
console.log("Dequeued:", linkedListQueue.dequeue()); // Output: 100
linkedListQueue.display(); // Output: Data is 200, Data is 300
linkedListQueue.enqueue(400);
linkedListQueue.display(); // Output: Data is 200, Data is 300, Data is 400
console.log("Dequeued:", linkedListQueue.dequeue()); // Output: 200
linkedListQueue.display(); // Output: Data is 300, Data is 400