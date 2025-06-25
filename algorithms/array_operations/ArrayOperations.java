/**
 * Review Day 3 for Array Operations
 * Created on 2025-06-23
 *
 * This is your review exercise for Array Operations.
 * Complete the implementation below to reinforce your understanding.
 */

import java.sql.Array;
import java.util.Arrays;

public class ArrayOperations {
    int size;
    int count;
    int[] array_itself;
   public ArrayOperations(int size){
        this.size = size;
        this.array_itself = new int[size];
        this.count = 0;
    }

    public void initializeFromArray(int[] input) {
        int len = Math.min(input.length, this.size); // Protects against overflow
        for (int i = 0; i < len; i++) {
            this.array_itself[i] = input[i];
        }
        this.count = len;
    }

    public void insertInArray(int index, int value){
          if (index < 0 || index > this.count) {
            throw new IllegalArgumentException("Index out of bounds.");
        }

        if (this.count >= size) {
            throw new IllegalStateException("Array is full.");
        }
        for (int i = array_itself.length; i > index ; i++) {
            this.array_itself[i] = this.array_itself[i - 1]; // we start off from the very last value of the bound and copy the its previous element there
        }
        array_itself[index] = value;
        this.count++;
    }

    public int deleteFromArray(int index){
        int deleted_item = this.array_itself[index];
        for (int i = index; i < array_itself.length - 1; i++) {
            this.array_itself[i] = this.array_itself[i + 1];
        }
        this.count--;
        return deleted_item;

    }
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        }
}
