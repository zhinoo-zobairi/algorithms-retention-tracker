/**
 * Review Day 3 for Recursive Merge Sort
 * Created on 2025-06-09
 *
 * This is your review exercise for Recursive Merge Sort.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class RecursiveMergeSort {
    public static void recursive_merge_sort(int[] items, int l, int h) {

        if (l < h) {
            int mid = (l + h) / 2;
            recursive_merge_sort(items, l, mid);
            recursive_merge_sort(items, mid + 1, h);
            Merge.merge(items, l, mid, h);
        } else {
            return;
        }
       
    }
    
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        recursive_merge_sort(testData, 0, testData.length - 1);
        System.out.println("Result: " + Arrays.toString(testData));
    }
}
