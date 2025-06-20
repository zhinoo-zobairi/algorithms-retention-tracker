/**
 * Review Day 3 for Stack Operations
 * Created on 2025-06-20
 *
 * This is your review exercise for Stack Operations.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class Stack {
// creating the boxes that the constructor will fill:
    int top;
    int size;
    int[] array; // declares a field called array: a box to store an array

    // the constructor must match the class name exactly
    public Stack(int size){
        this.top = -1;
        this.size = size;
        this.array = new int[size]; // actually allocating memory 
    }

    public void stack_operations_push(int[] items) {
            for (int i = 0; i < items.length; i++) {
                if (this.top == this.size - 1) {
                System.out.println("Stack Overflow");
                break;
                } else{
                this.top ++;
                this.array[this.top] = items[i];
                    }
                }
            }

    public int stack_operations_pop(){
        if (this.top == -1){
            System.out.println("Stack underflow");
            return -1; // make sure every possible path in your method guarantees a return.
        } else {
            int top_item = this.array[this.top];
            this.top --;
            return top_item;
        }
    }
    
    public int stack_operations_search(int value){
        for (int index = 0; index < this.array.length; index++) {
            if (this.array[index] == value) {
                return index;
            }  
        }
        return -1;
    }


    public static void main(String[] args) {
        Stack myStack = new Stack(6);
        int[] testData = {5, 2, 9, 1, 5, 6};
        myStack.stack_operations_push(testData);
    }
}

   /**
 * Stack Usage Analogy: Country & Citizenship
 * 
 * There are two ways to use methods in Java: `static` and `instance`.
 * 
 * 🔹 Static method (`Stack.push(myStack, 42)`):
 *    - Analogy: You're a foreigner borrowing a resource from another country.
 *    - You must **mention the country name** (class name) explicitly to use its resource.
 *    - The method belongs to the class itself, not any specific object.
 *    - Example:
 *        Stack myStack = new Stack(6);
 *        Stack.push(myStack, 42); // borrowing a method from the class
 * 
 * 🔸 Instance method (`myStack.push(42)`):
 *    - Analogy: You’re a citizen using your own country’s services.
 *    - The object (`myStack`) already belongs to the class (country),
 *      so you **don't need to specify the class name again**.
 *    - The method belongs to the instance, and uses `this` internally to access fields.
 *    - Example:
 *        Stack myStack = new Stack(6);
 *        myStack.push(42); // accessing method as a local citizen
 * 
 * `this` keyword:
 *    - Think of it as your **passport** when you’re inside your own country.
 *    - It helps refer to your own fields and methods without confusion.
 * 
 * Summary:
 *    - Static methods → outsiders accessing public services → must name the country.
 *    - Instance methods → citizens using local services → no need to name the country.
 */