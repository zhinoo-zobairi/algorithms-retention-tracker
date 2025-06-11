/**
 * Review Day 3 for Counting Sort
 * Created on 2025-06-11
 *
 * This is your review exercise for Counting Sort.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class CountingSort {

    public static int findMax(int[] items){
            int largest = items[0];
            for (int index = 1; index < items.length; index++) {
                if (items[index] > largest) {
                    largest = items[index];
            }
        }
        return largest;
    }
    public static void counting_sort(int[] items) {
        int max = findMax(items);
        int[] count = new int[max + 1]; // to accommodate 0 up until max
        // count.fill(count, 0); // Unnecessary for int[]. Java fills the entire array with zeroes by default. Java automatically initializes arrays of primitive types.
        
        for (int index = 0; index < items.length; index++) {
            count[items[index]] ++;
        }
        int k = 0;
        for (int i = 0; i < count.length; i++) {
            while (count[i] > 0) {
                items[k++] = i;
                count[i] --;
            }
        }

    }
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        counting_sort(testData);
        System.out.println("Result: " + Arrays.toString(testData));
    }
}
//  O(n + k) because every element is touched a fixed number of times