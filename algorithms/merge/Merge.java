/**
 * Review Day 3 for Merge
 * Created on 2025-05-31
 *
 * This is your review exercise for Merge.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class Merge {
   
    public static void merge(int[] items, int left, int mid, int right) {
        int i = left;        // Start of left half
        int j = mid + 1;     // Start of right half
        int k = 0;           // Index in temp[]
        int size = right - left + 1;
        int[] temp = new int[size];
        while (i <= mid && j <= right){
            if (items[i]<= items[j]) {
                temp[k] = items[i];
                i++;
                k++;
            } else {
                temp[k] = items[j];
                j++;
                k++;
            }
        }
        while (i<= mid) {
            temp[k++] = items[i++];
            
        }
        while (j<=right) {
            temp[k++] = items[j++];
        }
        
        for (int m = 0; m < temp.length; m++) {
            items[left + m] = temp[m];
        }
    }
    
    public static void main(String[] args) {
        int[] testData = {2, 5, 9, 1, 5, 6};
        merge(testData, 0, 2, 5);             // Merge left=0, mid=2, right=5
        System.out.println("Result: " + Arrays.toString(testData));
    }
}
