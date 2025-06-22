/**
 * Review Day 56 for Recursive List Reversal
 * Created on 2025-06-22
 *
 * This is your review exercise for Recursive List Reversal.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class RecursiveListReversalReview {
    int[] array;
    public RecursiveListReversalReview (int[] elements) {
        this.array = elements;
    }
    private void recursive_list_reversal_helper(int l, int h) {
        
    if (l >= h) return;

    int temp = array[l];
    array[l] = array[h];
    array[h] = temp;
    recursive_list_reversal_helper(l + 1, h - 1);

    }
    public void recursive_list_reversal() {
        recursive_list_reversal_helper(0, this.array.length - 1);
    }
    
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        RecursiveListReversalReview myArray = new RecursiveListReversalReview(testData);
        myArray.recursive_list_reversal();
        System.out.println("Result: " + Arrays.toString(testData));
    }
}
