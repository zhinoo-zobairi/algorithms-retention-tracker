/**
 * Review Day 7 for Hashing
 * Created on 2025-06-27
 *
 * This is your review exercise for Hashing.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Hashing
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

class LinkedList {
    constructor() {
        this.head =  null;
    }
    insert(value){
        const node = new Node(value);
        node.next = this.head;
        this.head = node;
    }
    print(){
        let current = this.head;
        let output = '';
        while (current != null) {
            output += `${current.value} -> `;
            current = current.next;
            }
        output += 'null';
        console.log(output);
    }
}

class HashTable {
    constructor(size) {
        this.size = size;
        this.buckets = [];
        for (let index = 0; index <= this.size - 1; index++) {
            this.buckets[index] = new LinkedList();
        }
    }
    hashFunction(value){
        return value % this.size;
    }
    insert(value){
        const index = this.hashFunction(value);
        this.buckets[index].insert(value);
    }
    print() {
    for (let i = 0; i < this.size; i++) {
        process.stdout.write(`Bucket ${i}: `);
        this.buckets[i].print();
        }
    }
}

const table = new HashTable(10);

table.insert(5);
table.insert(15);
table.insert(25);
table.insert(7);
table.insert(17);
table.insert(9);

table.print();
