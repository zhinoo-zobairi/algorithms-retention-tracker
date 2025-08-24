/**
 * Review Day 56 for Merge
 * Created on 2025-07-23
 *
 * This is your review exercise for Merge.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class MergeReview {
    public static int[] merge(int[] items_1, int[] items_2) {
        int i = 0, j = 0, k = 0;
        int[] temp = new int[items_1.length + items_2.length];
        while (i < items_1.length && j < items_2.length){
            if (items_1[i] <= items_2[j]){
                temp[k] = items_1[i];
                i ++;
            }else{
                temp[k] = items_2[j];
                j ++;
            }
            k ++;
        }
        while (i < items_1.length){
            temp[k] = items_1[i];
            i ++;
            k ++;
        }
        while (j < items_2.length){
            temp[k] = items_2[j];
            j ++;
            k ++;
        }
        return temp;
    }
    
    public static void main(String[] args) {
        int[] testData1 = {1, 2, 3, 20};
        int[] testData2 = {10, 12, 13, 18};
        int[] mergedResult = merge(testData1, testData2);
        System.out.println("Result: " + Arrays.toString(mergedResult));
    }
}
