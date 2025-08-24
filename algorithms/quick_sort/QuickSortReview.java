/**
 * Review Day 56 for Quick Sort
 * Created on 2025-07-13
 *
 * This is your review exercise for Quick Sort.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class QuickSortReview {
    int array[];
    int size;
    public QuickSortReview(int array[], int size){
        this.size = size;
        this.array = Arrays.copyOf(array, size); // allocates and copies the elements over
    }
    public void sort() { // since this is the public entry point, just name it sort() to match Java conventions
        this.quick_sort(0, this.size - 1);
    }
    public void quick_sort(int l, int h){
        if(l < h) {
        int index = this.partition(l, h);
        this.quick_sort(l, index - 1); // In Hoare’s partition scheme, when partition() returns an index p, the pivot is not guaranteed to be at p.
        this.quick_sort(index + 1, h); // We do not exclude p, because it’s not “the pivot index” in the same sense as in Lomuto’s scheme.
        }
    }
    private void swap(int[] array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    }

    private int partition(int l, int h) {

    int pivotIndex = l + (int)(Math.random() * (h - l + 1));
    
    swap(array, pivotIndex, h);
    
    int pivot = array[h];    // algorithm’s logic assumes the pivot is at the end
    
    int i = l;
    
    for (int j = l; j < h; j++) {
        if (array[j] <= pivot) {
            swap(array, i, j);
            i++;
        }
    }
    
    swap(array, i, h);
    
    return i;
}
    
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        QuickSortReview sorter = new QuickSortReview(testData, testData.length);
        sorter.sort();
        System.out.println("Result: " + Arrays.toString(sorter.array));
    }
}
