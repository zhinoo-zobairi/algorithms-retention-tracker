/**
 * Review Day 3 for Insertion Sort
 * Created on 2025-04-29
 *
 * This is your review exercise for Insertion Sort.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class InsertionSort {
    
    public static void insertion_sort(int[] items) {
        for (int i = 1; i < items.length; i++){
            int temp = items[i];
            int j = i - 1;
            while (j>=0 && items[j] > temp){
                items[j+1] = items[j];
                j--;
            }
            items[j+1] = temp;
        }
    }
  public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        insertion_sort(testData);
        System.out.println("Result: " + Arrays.toString(testData));
    }
}
