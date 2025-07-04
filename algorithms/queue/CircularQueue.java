/**
 * Review Day 3 for Queue
 * Created on 2025-07-02
 *
 * This is your review exercise for Queue.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;

public class CircularQueue {
    int front;
    int rear;
    int[] items;
    int size;
    public CircularQueue(int size){
        this.size = size;
        this.items = new int[size];
        this.rear = -1; 
        this.front = -1; // in Java we cannot assign null to a primitive type, so I use sentinel
    }
    public void enqueue(int value) { 
        if((this.rear + 1) % this.size == this.front){
            System.out.println("Queue is full");
        }
        else {
            if (this.front == -1) this.front = 0; // the first time we enqueue wwe must initialize front to a valid index
            this.rear = (this.rear + 1) % this.size;
            this.items[this.rear] = value;
        }
    }

    public int dequeue() { 
        if (this.front == -1){
            System.out.println("Queue is already empty");
            return -1;
        }
        else {
        int value = this.items[this.front];
        if (this.front == this.rear) {
            this.front = this.rear = -1;
        } else {
            this.front = (this.front + 1) % this.size;
            }
        return value;
        }
    }

    public void display() { 
        if ((this.rear + 1) % this.size == this.front){
            System.out.println("Queue is empty");
        }
        else{
            int current = this.front;
            while (current != this.rear + 1){
                System.out.println(this.items[current]);
                current = (current + 1) % this.size;
            }
        }
    }
    
    
    public static void main(String[] args) {
        Queue queue = new Queue(6);
        queue.enqueue(5);
        queue.enqueue(2);
        queue.enqueue(9);
        queue.enqueue(1);
        queue.enqueue(5);
        queue.enqueue(6);

        queue.display();
        queue.dequeue();
        queue.display();
    }
}
