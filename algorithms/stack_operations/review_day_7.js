/**
 * Review Day 7 for Stack Operations
 * Created on 2025-06-24
 *
 * This is your review exercise for Stack Operations.
 * Complete the implementation below to reinforce your understanding.
 */

/**
 * Implementation of Stack Operations
 * @param {Array} items - The array to process
 * @returns {Array} - The processed array
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
class Stack {
    constructor(size) {
        this.top = -1;
        this.array = new Array(size); // preallocate space
        this.size = size;
    }

stack_operations_push(data) {
    if (this.top == this.size -1) {
        throw new Error("Stack Overflow");
    } else {
        this.top ++;
        this.array[this.top] = data;
    }
}
stack_operations_pop() {
    if (this.top == -1) {
        throw new Error("Stack Underflow"); 
    } else {
        const value = this.array[this.top];
        this.top --;
        return value;
    }
}

stack_operations_display(){
    for (let index = 0; index <= this.top; index++) {
        console.log("the element is", this.array[index])
    }
}
}


const stack = new Stack(5);
stack.stack_operations_push(19);
stack.stack_operations_push(42);
stack.stack_operations_push(7);
stack.stack_operations_display();      
console.log(stack.stack_operations_pop()); 
stack.stack_operations_display();