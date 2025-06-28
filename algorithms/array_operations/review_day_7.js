/**
 * Review Day 7 for Array Operations
 * Created on 2025-06-27
 *
 * This is your review exercise for Array Operations.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Array Operations
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */

class MyArray{
    constructor(size){
        this.array = new Array(size); // preallocate space for future items
        this.size = size;
        this.length = 0;
    }
    initializeFromArray(input){
        if (input.length > this.size) {
        throw new Error("Input array exceeds allocated size.");
    }  
        for (let index = 0; index < input.length; index++) {
            this.array[index] = input[index];
            this.length += 1;
        }
    }
    sort(){
       for (let index = 1; index < this.length; index++) {
        const key = this.array[index];
        let j = index - 1;
        while (j >= 0 && this.array[j] > key) {
            this.array[j + 1] = this.array[j];
            j--;
        }
        this.array[j + 1] = key;
       }
    }

    removeDuplicates() {
    const unique = [];

    for (let i = 0; i < this.length; i++) {
        let isDuplicate = false;

        for (let j = 0; j < unique.length; j++) {
            if (this.array[i] === unique[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            unique.push(this.array[i]);
        }
    }

    this.array = unique;
    this.length = unique.length;
}
    print() {
        for (let i = 0; i < this.length; i++) {
            console.log(`Element ${i}: ${this.array[i]}`);
        }
}
}


const testData = [5, 2, 9, 1, 5, 6];
const array_new = new MyArray(10);
array_new.initializeFromArray(testData);
array_new.print();           
array_new.sort();          
array_new.removeDuplicates(); 
array_new.print();  
