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
    public void insert_head(int data, Node head){
        int key = this.hashFunction(data);
        Node new_node = new Node(data);
        new_node.next = bucket[key];
        bucket[key] = new_node;
    }
}
