/**
 * Review Day 3 for Hashing
 * Created on 2025-06-23
 *
 * This is your review exercise for Hashing.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class HashTable {
    Node[] buckets; // In Java, once we define a class — any class — we can absolutely create an array of that class
    public HashTable(int size){
        this.buckets = new Node[size];
    }
    public int hashFunction(int key){
        return key % buckets.length;
    }
    public void insert_head(int key){
        int index = this.hashFunction(key);
        Node newNode = new Node(key);
        newNode.next = buckets[index];
        buckets[index] = newNode;
    }

    public void printTable() {
        for (int i = 0; i < this.buckets.length; i++) {
            Node temp = this.buckets[i]; // This points to the actual start of the chain at index i
            System.out.print("Bucket " + i + ": ");
            while (temp != null) {
                System.out.print(temp.value + " -> ");
                temp = temp.next;
            }
            System.out.println("NULL");
        }
    }

    public boolean contains(int data) {
        for (int i = 0; i < buckets.length; i++) {
            Node temp = buckets[i];
            while (temp != null) {
                if (temp.value == data) {
                    return true;
                } 
                temp = temp.next;
            }
        }
        return false;
    }

    public int delete(int data){
        int index = hashFunction(data);
        Node current = buckets[index];
        Node prev = null;
        while (current != null && current.value != data) {
            prev = current;
            current = current.next;
        }
        if (current == null) return -1;

        if (prev == null) {
            buckets[index] = current.next;
        } else {
           prev.next = current.next;
        // from buckets[index] → Node A → current → Node C → ... to buckets[index] → Node A → Node C → ...
        }
        return current.value;
    }
    public static void main(String[] args) {
    HashTable table = new HashTable(5); 

    table.insert_head(10);
    table.insert_head(15);
    table.insert_head(20);
    table.insert_head(3);
    table.insert_head(8);

    System.out.println("After inserting values:");
    table.printTable(); 

    System.out.println("\nContains 15? " + table.contains(15)); 
    System.out.println("Contains 99? " + table.contains(99));
    System.out.println("\nDeleting 20 (head of chain): " + table.delete(20));
    table.printTable();
}
}

class Node {
    int value;
    Node next;
    public Node(int value){
        this.value = value;
        this.next = null;
    }
}