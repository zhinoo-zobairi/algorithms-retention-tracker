/**
 * Review Day 56 for Binary Heap Insert Operation
 * Created on 2025-06-30
 *
 * This is your review exercise for Binary Heap Insert Operation.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class BinaryHeapInsertOperationReview {
    int[] heap;
    int size;
    
    int count;

    BinaryHeapInsertOperationReview(int size){
        this.size = size;
        this.heap = new int[size]; // fixed-size array
        this.count = 0;
    }

    public void binary_heap_insert(int new_value) {
        if (this.count == this.size){
            System.out.println("Heap is full!");
        } else {
            int i = this.count + 1; // First available index in a 1-based heap
            this.heap[i] = new_value;
            while (i >= 1 && new_value < this.heap[i / 2]){
                this.heap[i] = this.heap[i/2];
                i = i/2;
            }
            this.heap[i] = new_value;
            this.count++;
        }
    }
    public void binary_heap_build(int[] new_values) {
        if (this.size >= new_values.length) {
            for (int i = 0; i < new_values.length; i++) {
                this.binary_heap_insert(new_values[i]);
            }
        } else {
    System.out.println("Error: Input array is too large for the heap size.");
        }
    }

    public void binary_heap_display() {
        for (int i = 1; i < this.count + 1; i++){
            System.out.print(this.heap[i] + " ");
            System.out.println();
        }
    }
    public static void main(String[] args) {
        BinaryHeapInsertOperationReview my_heap = new BinaryHeapInsertOperationReview(10);
        heap.binary_heap_build(new int[]{4, 7, 2, 9, 1});
        my_heap.binary_heap_insert(5);
        my_heap.binary_heap_display();
    }
}
