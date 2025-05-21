/**
 * Review Day 3 for Quick Sort
 * Created on 2025-05-21
 *
 * This is your review exercise for Quick Sort.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class QuickSort {
    private int[] arr; // This variable can only be accessed inside this class. We’re writing a class that remembers the array it’s going to sort. So we declare a field (arr) to hold it permanently
    public QuickSort(int[] input) {
        this.arr = input;   // Take the array the user gives me (called input)…and store it in my own field called arr.
        // Think of arr as a RAM slot inside your object. We define it at the class level (private int[] arr;). We fill it with a real array in the constructor (this.arr = input;). We access it later in sort methods: like this.arr[i] = ...;
    }

    public void sort() { // In Java, we use 3 methods to keep things clean and modular, unlike C/Python where we write everything in one place because we don’t build full classes. If we’re using this.arr or accessing object-specific memory, method must NOT be static. It is public, because we want the outside world (like your main() method or another class) to be able to say: sorter.sort()
        quickSort(0, arr.length - 1);    
    }

    private void quickSort(int low, int high){
        if (low < high) {
            int p = partition(low, high);
            quickSort(low, p-1);
            quickSort(p + 1, high);
        }
    }
    
    private int partition(int low, int high) {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        while (i<=j) {
            while (i <= j && arr[i] < pivot) {
                i++;
            }
            while (i <= j && arr[j] > pivot) {
                j--;
            }
            if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else {
            break;
        }   
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        return j;
    }
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        QuickSort sorter = new QuickSort(testData);
        sorter.sort();
        System.out.println("Result: " + Arrays.toString(testData));
    }
}
