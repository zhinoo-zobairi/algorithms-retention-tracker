/**
 * Review Day 56 for Heap Deletion and Sort Max Heap
 * Created on 2025-07-06
 *
 * This is your review exercise for Heap Deletion and Sort Max Heap.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class HeapDeletionAndSortMaxHeapReview {
    int[] items;
    int size;
    public HeapDeletionAndSortMaxHeapReview(int[] items){
        this.items = items;
        this.size = items.length;
        buildMaxHeap();
    }
    public void buildMaxHeap(){
        for (int i = (size - 2) / 2; i >= 0; i--) { // for any node to have at least one child, the condition must hold: 2 * i + 1 < size. So, int lastParent = (size - 2) / 2; We don’t care about the right child; even a single left child makes it an internal node
            heapifyDown(i);
        }
    }

    public void heapifyDown(int i){
        
        while (2 * i + 1 < this.size ) { // as long as the left child exists
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int bigger_child = 2 * i + 1;
        if (right_child < size && items[right_child] > items[left_child]) { // Guarded against ArrayIndexOutOfBounds for right_child
            bigger_child = 2 * i + 2;
        }
        if (this.items[i] < this.items[bigger_child]) {
            int temp = this.items[i];
            this.items[i] = this.items[bigger_child];
            this.items[bigger_child] = temp;
        }else{
            break;
        }
        i = bigger_child;
        }
    }

    public int heapDeletion() {
        int deleted = this.items[0];
        this.items[0] = this.items[size - 1];
        size--;
        heapifyDown(0);
        return deleted;
    }
    public int[] heapSort(){
        int[] sorted = new int[this.size];
        int i = 0;
        int n = this.size; 
        while (this.size > 0) {
            int deleted = heapDeletion();
            sorted[n - i - 1] = deleted;
            i++;
        }
        return sorted;
    }
    
    public static void main(String[] args) {
    int[] testData = {5, 2, 9, 1, 5, 6};
    System.out.println("Original Array: " + Arrays.toString(testData));

    HeapDeletionAndSortMaxHeapReview heap = new HeapDeletionAndSortMaxHeapReview(testData);
    System.out.println("Max Heap: " + Arrays.toString(heap.items));

    int[] sortedData = heap.heapSort();
    System.out.println("Sorted Array: " + Arrays.toString(sortedData));
    }
}
