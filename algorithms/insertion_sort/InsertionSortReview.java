/**
 * Review Day 56 for Insertion Sort
 * Created on 2025-06-21
 *
 * This is your review exercise for Insertion Sort.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class InsertionSortReview {
    int[] array;
    public InsertionSortReview(int[] elements){
        this.array = elements;
    }
    public void insertion_sort() {
        for (int i = 1; i < array.length; i++) {
            int key = this.array[i];
            int j = i - 1;
            while (j >= 0 && key < this.array[j]) {
                this.array[j + 1] = this.array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
    
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        InsertionSortReview array = new InsertionSortReview(testData);
        array.insertion_sort();
        System.out.println("Result: " + Arrays.toString(testData));
    }
}
