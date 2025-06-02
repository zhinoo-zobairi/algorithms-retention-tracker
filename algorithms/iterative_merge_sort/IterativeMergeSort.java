/**
 * Review Day 3 for Iterative Merge Sort
 * Created on 2025-06-02
 *
 * This is your review exercise for Iterative Merge Sort.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class IterativeMergeSort {
    
    public static void iterative_merge_sort(int[] items) {
        
        for (int size = 1; size < items.length; size*=2) {
            for (int start = 0; start < items.length; start += 2 * size) {
                int mid = Math.min(start+size-1, items.length - 1);
                int end = Math.min(start+ 2*size - 1, items.length - 1);
                if (mid < end) {
                Merge.merge(items, start, mid, end); // Only call merge if there’s actually a right half to merge into the left
            }
            }
            
        }
    }
    
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        iterative_merge_sort(testData);
        System.out.println("Result: " + Arrays.toString(testData));
    }
}
