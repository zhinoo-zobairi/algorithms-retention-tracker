/**
 * Review Day 56 for Hashing
 * Created on 2025-08-15
 *
 * This is your review exercise for Hashing.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

class Node {
    int value;
    Node next;
    Node(int value){
        this.value = value;
        this.next = null;
    }
}

public class HashTableReview {
    Node[] bucket;
    public HashTableReview(int size){
        this.bucket = new Node[size];
    }
    public int hashFunction(int data){
        int key = data % bucket.length;
        return key;
    }
    public void insert_head(int data){ //  I do not need to guard against the bucket being empty in this case. Because in Java all elements are initialized to null by default.
        int key = this.hashFunction(data);
        Node new_node = new Node(data);
        new_node.next = bucket[key];
        bucket[key] = new_node;
    }
    public void insert_tail(int data){
        int index = this.hashFunction(data);
        Node new_node = new Node(data);
        if (this.bucket[index] == null) {
        this.bucket[index] = new_node;
        } else { 
        Node current = this.bucket[index];
        while (current.next != null) {
            current = current.next;
        }
        current.next = new_node;
        }
    }
    public void print_bucket(int index){
        Node current =bucket[index];
        int i = 0;
        while (current!= null) {
            System.out.println("The value of node" + i + "is" + current.value);
            current = current.next;
            i++;
        }
    }
    public void print_table(){
        for (int i = 0; i < bucket.length; i++) {
            Node current = bucket[i];
            while (current != null) {
                System.out.println(current.value);
                current = current.next;
            }
        }
    }
    public boolean contains(int data) {
        int index = this.hashFunction(data);
        Node current = this.bucket[index];
        while (current != null) {
            if (current.value == data) {
                return true;
            }
            current = current.next;
        }
        return false;
    }
    public void delete_meth1(int data) { // Check 3 cases: if the bucket is empty, if the head is the value, if it is deeper in the chain of the bucket-cell.
        int index = this.hashFunction(data);
        Node current = this.bucket[index];
        Node prev = null;
        while (current != null) {
            if (current.value == data) {
                if (prev == null) {
                    
                    this.bucket[index] = current.next;
                } else {
                    prev.next = current.next;
                }
                return;
            }
            prev = current;
            current = current.next;
        }
    }

    public void delete_meth2(int data) {
        int index = this.hashFunction(data);
        Node current = this.bucket[index];
        if (current == null) return; // bucket empty
        if (current.value == data) {
            this.bucket[index] = current.next; // if I put null there, then I will set the whole bucket to null!
            return;
        }
        while (current.next != null) {
            if (current.next.value == data){
            current.next = current.next.next;
            return;
            }
            current = current.next;
        }
    }
    public static void main(String[] args) {
    HashTableReview table = new HashTableReview(5); 

    table.insert_head(10);
    table.insert_head(15);
    table.insert_head(20);
    table.insert_head(3);
    table.insert_head(8);

    System.out.println("After inserting values:");
    table.print_table(); 

    System.out.println("\nContains 15? " + table.contains(15)); 
    System.out.println("Contains 99? " + table.contains(99));
    table.print_table();
}
}
