/**
 * Review Day 56 for Counting Sort
 * Created on 2025-08-03
 *
 * This is your review exercise for Counting Sort.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class CountingSortReview {

    int[] arr;
    int size;

    CountingSortReview(int arr[]){
        this.arr = arr;
        this.size = arr.length;
    }
    public void counting_sort() {
        int max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        int aux_size = max + 1;
        int[] aux = new int[aux_size];
        for (int i = 0; i < this.size; i++){
            aux[arr[i]]++;
        }
        int j = 0;
        for(int i = 0; i < aux_size; i++){
            while (aux[i] != 0) {
                this.arr[j] = i;
                j++;
                aux[i]--;
            }
        }
    }
    
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        CountingSortReview items = new CountingSortReview(testData);
        items.counting_sort();
        System.out.println("Result: " + Arrays.toString(testData));
    }
}
