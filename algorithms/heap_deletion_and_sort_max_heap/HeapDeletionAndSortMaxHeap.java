/**
 * Review Day 3 for Heap Deletion and Sort Max Heap
 * Created on 2025-05-14
 *
 * This is your review exercise for Heap Deletion and Sort Max Heap.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class HeapDeletionAndSortMaxHeap { // HeapDeletionAndSortMaxHeap object has the following fields:
    int[] array;
    int size;
    HeapDeletionAndSortMaxHeap(int[] array){ // constructor: takes only the array, infers size, assigns fields (setting up the object’s state)
        this.array = Arrays.copyOf(array, array.length); // Deep copy of input → internal state is now decoupled from the caller’s data.
        this.size = array.length; 
    }
  public int leftChild(int i) {
    return 2*i + 1;
}
public int rightChild(int i) {
    return 2*i + 2;
}

public void swap(int i, int j){
    int temp = this.array[i];
    this.array[i] = this.array[j];
    this.array[j] = temp;
}

    public int[] heapDeletionAndSortMaxHeap() {
        int[] deleted_elements = new int[size];
        int insertion_index = 0;
        while (this.size > 0) { // We repeat until we deleted each element in the array and added them to the new list(deleted_elements)
            int deleted_element = this.array[0];
            deleted_elements[insertion_index] = deleted_element;
            insertion_index++;
             this.array[0] = this.array[size-1];
             this.size--;
             int i = 0;
             while (leftChild(i) < this.size) { // We insert a new element at index 0 (and move the last element there), then we compare it to its children and keep swapping it down with the larger child until the heap property is restored (or no more children exist.)
                int largerChildIdx;
                if (rightChild(i) < this.size && this.array[rightChild(i)]>this.array[leftChild(i)]) {
                    largerChildIdx = rightChild(i);
                } else{
                    largerChildIdx = leftChild(i);
                }
                if (this.array[largerChildIdx] > this.array[i]) {
                    swap(i, largerChildIdx);
                    i = largerChildIdx;
                } else {
                    break;
                }
             }
        }
        return deleted_elements;
    }

    //You’re expected to pass a valid max-heap. The constructor will not validate or build it for you.
    public static void main(String[] args) {
        int[] testData = {9, 5, 6, 1, 2, 5};
        HeapDeletionAndSortMaxHeap heap = new HeapDeletionAndSortMaxHeap(testData);
        int[] result = heap.heapDeletionAndSortMaxHeap();
        System.out.println("Result: " + Arrays.toString(result));
        
    }
}
