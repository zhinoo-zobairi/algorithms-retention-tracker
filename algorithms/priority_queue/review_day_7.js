/**
 * Review Day 7 for Priority Queue
 * Created on 2025-07-08
 *
 * This is your review exercise for Priority Queue.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Priority Queue
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
const { LinkedListQueue, ArrayQueue } = require('../queue/review_day_7');
class ExplicitPriorityQueue {
    constructor(capacity) {
        this.capacity = capacity
        this.count = 0
        this.array = new Array(capacity);
    }

    enqueue(value, priority) {
        if (this.count == this.capacity) {
            console.log("Queue is full");
        } else {
            this.array[this.count] = [value, priority];
            this.count++;
        }
    }

    dequeue() {
        let min =this.array[0][1];
        let minIndex = 0;
        for (let index = 0; index < this.count; index++) {
            if (this.array[index][1] < min) {
                min = this.array[index][1];
                minIndex = index;
            }            
        }
        const deleted = this.array[minIndex][0];
        this.array[minIndex] = this.array[this.count - 1];
        this.count--;
        return deleted
    }

    display() {
        if (this.count == 0) {
            console.log("Queue is empty");
        }
        for (let index = 0; index < this.count; index++) {
            const [value, priority] = this.array[index];
            console.log(`Value: ${value}, Priority: ${priority}`);
        }
    }
}
class MultiQueueArrayPriorityQueue {
    constructor(maxPriority, capacity) {
        this.maxPriority = maxPriority;
        this.array = Array.from({ length: maxPriority + 1 }, () => new ArrayQueue(capacity));// Array.from() is a built-in method in JavaScript that creates a new array... { length: maxPriority + 1 }, tells how many items, () => new LinkedListQueue() what to put at each index: The () are the parameter list. The => means “returns”: new ArrayQueue() is the value to return each time.
    }

    enqueue(item, priority) {
        if (priority < 0 || priority > this.maxPriority) {
            console.log("Priority is not valid");
            return;
        }
        this.array[priority].enqueue(item);
    }

    dequeue() {
        for (let index = 0; index <= this.maxPriority; index++) {
                if (this.array[index].size > 0) {
                return this.array[index].dequeue();
            }
        }
            console.log("All queues are empty.");
        }
    display() {
        for (let index = 0; index <= this.maxPriority; index++) {
            console.log(`Priority ${index}:`);
            this.array[index].display();
        }
    }
}
// Test the implementation
if (require.main === module) {
    // Test the implementation
    const multiQueue = new MultiQueueArrayPriorityQueue(3, 5); // maxPriority = 3, capacity = 5
    multiQueue.enqueue(10, 1);
    multiQueue.enqueue(20, 2);
    multiQueue.enqueue(30, 0);
    multiQueue.display();
    console.log("Dequeued:", multiQueue.dequeue());
    multiQueue.display();
}