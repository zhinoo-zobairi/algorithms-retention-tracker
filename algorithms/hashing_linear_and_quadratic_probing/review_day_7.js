/**
 * Review Day 7 for Hashing Linear and Quadratic Probing
 * Created on 2025-07-05
 *
 * This is your review exercise for Hashing Linear and Quadratic Probing.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Hashing Linear and Quadratic Probing
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
class HashMap {
    constructor(size) {
        this.buckets = new Array(size);
        for (let index = 0; index < size; index++) {
            this.buckets[index] = -1;
        }
        this.size = size;
    }
    insert(key){
        let index = this.hashFunction(key);
        if (this.buckets[index] != -1) {
            index = this.hashing_linear_probing(key); 
        }
        this.buckets[index] = key;
    }
    insertArray(items){
        for (let index = 0; index < items.length; index++) {
            this.insert(items[index]);
        }
    }
    hashFunction(key){
        if (typeof key == "number") {
            return key % this.size;
        } else if (typeof key === 'string') {
            let code = 0;
            // In JavaScript, a string is an array-like object of characters: You can’t call .map() or .forEach() directly (those are array methods), but you can loop over a string’s indices using:
            for (let i = 0; i < key.length; i++) {
                code += key.charCodeAt(i);
            }
            return code % this.size;
        } else {
    throw new Error('Unsupported key type');
        }
    }

    hashing_linear_probing(key) {
        let i = 0;
        const original_index = this.hashFunction(key);
        let probing_index = (original_index + i) % this.size;
        while (this.buckets[probing_index] != -1) {
            i++;
            probing_index = (original_index + i) % this.size;
        }
        return probing_index;
    }
    hashing_quadratic_probing(key){
        original_index = this.hashFunction(key);
        let i = 1;
        let probing_index = (original_index + i*i) % this.size;
        while (this.buckets[probing_index] != -1) {
            i++;
            probing_index = (original_index + i*i) % this.size;
        }
        return probing_index;
    }
    display() {
        console.log('Hash Table:', this.buckets); // In JavaScript, console.log() can directly display arrays and objects
    }
}



console.log("Testing HashMap with numbers:");
const testData = [5, 2, 9, 1, 5, 6];
const hashMap = new HashMap(10);
hashMap.insertArray(testData);
hashMap.display();

console.log("\nTesting HashMap with strings:");
const hashTable = new HashMap(3);
const testStr = ['aa', 'dd', 'abc'];
hashTable.insertArray(testStr);
hashTable.display();
