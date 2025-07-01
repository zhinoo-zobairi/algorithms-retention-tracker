/**
 * Review Day 3 for Hashing Linear and Quadratic Probing
 * Created on 2025-07-01
 *
 * This is your review exercise for Hashing Linear and Quadratic Probing.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class HashingLinearAndQuadraticProbing {
    int size;
    int[] hashTable;
    public HashingLinearAndQuadraticProbing(int size){
        this.size = size;
        this.hashTable = new int[size]; // every element is automatically initialized to 0 by default but if input values can contain 0, then I lose the ability to distinguish between: a real inserted 0, and a default ‘empty’ 0 => This is where sentinel values come in:
        for (int i = 0; i < size; i++) {
            this.hashTable[i] = -1;
        }
    }
    public int hashFunction(int value){
        int index = value % this.size;
        return index;
    }
    public void hashing_linear_probing(int value) {
        int index = hashFunction(value);
        int i = 0;
        int probing_index = index;
        while (i < this.size && this.hashTable[probing_index] != -1) {
            i++;
            probing_index = (index + i) % this.size;
        }
        if (i == this.size) {
            System.out.println("Hash table is full. Cannot insert: " + value);
            return;
        }
        this.hashTable[probing_index] = value;
    }

     public void hashing_quadratic_probing(int value) {
        int index = hashFunction(value);
        int i = 0;
        while (i< this.size && this.hashTable[(index + i*i) % this.size] != -1) { // while (i < this.size && slot not free)
            i++;
        }
        if (i == this.size) { // after the loop, if i == this.size, we don't want to get ArrayIndexOutOfBoundsException or invalid insert
            System.out.println("Hash table is full. Cannot insert: " + value);
            return;
        }
        this.hashTable[(index + i*i) % this.size] = value; 
     }

     public void displayTable() {
        System.out.println(Arrays.toString(this.hashTable));
    }
    public static void main(String[] args) {
     HashingLinearAndQuadraticProbing ht = new HashingLinearAndQuadraticProbing(5);
     ht.hashing_linear_probing(2);
     ht.hashing_linear_probing(22);
     ht.hashing_quadratic_probing(32);
     ht.displayTable();
    }
}
