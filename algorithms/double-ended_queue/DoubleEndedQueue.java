/**
 * Review Day 3 for Double-Ended Queue
 * Created on 2025-07-04
 *
 * This is your review exercise for Double-Ended Queue.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

class Node{
    int value;
    Node next; // reference to next node
    Node prev; // can’t pinpoint an exact use case. However, its necessity will become evident during design.
    Node(int data){
        this.value = data;
        this.next = null;
        this.prev = null;
    }
}
public class DoubleEndedQueue {
    Node rear;
    Node front;
    int size;
    DoubleEndedQueue(){
        this.rear = null;
        this.front = null;
        this.size = 0;
    }
    void addFront(int value){
        if (this.rear == null && this.front == null) {
            Node new_node = new Node(value);
            this.front = new_node;
            this.rear = new_node;
        }else {
            Node new_node = new Node(value);
            this.front.prev = new_node;
            new_node.next = this.front;
            this.front = new_node;
        }
        this.size ++;
    }
    void addLast(int value){
        if (this.rear == null && this.front == null) {
            Node new_node = new Node(value);
            this.front = new_node;
            this.rear = new_node;
        }else {
            Node new_node = new Node(value);
            this.rear.next = new_node;
            new_node.prev = this.rear;
            this.rear = new_node;
        }
        this.size++;
    }

    void display(){
        Node current = this.front; // We don’t want to create a new node; we just need a reference pointing to the existing front node.
        while(current != null){
            if (current.next != null){
            System.out.print(current.value + " -> ");
            } else {
                System.out.print(current.value);
            }
            current = current.next;
        }
    }
    void displayReverse(){
        Node current = this.rear;
        while(current != null){
            if (current.prev != null){
            System.out.print(current.value + " -> ");
            } else {
                System.out.print(current.value);
            }
            current = current.prev;
            }
        }
    }
    public static void main(String[] args) {
        DoubleEndedQueue deque = new DoubleEndedQueue();
        deque.addFront(10);
        deque.display();
        deque.addLast(30);
        deque.display();
    }
}
