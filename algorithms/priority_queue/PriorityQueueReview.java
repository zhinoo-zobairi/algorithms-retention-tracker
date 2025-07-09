/**
 * Review Day 3 for Priority Queue
 * Created on 2025-07-04
 *
 * This is your review exercise for Priority Queue.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.PriorityQueue;
/*
 * 🔹 Java Type System Quick Reference 🔹   Type<GenericParameter> var = new Implementation<>();
 * 
 * ▶ Interface:
 *   - A contract that defines method signatures, but no implementation.
 *   - Cannot be instantiated directly.
 *   - Example:
 *       List<Integer> myList = new ArrayList<>(); // List is the interface, just a contract: it can refer to any list-like class (ArrayList, LinkedList, etc.)
 *
 * ▶ Concrete Class:
 *   - A fully implemented class that you can instantiate directly.
 *   - Example:
 *       PriorityQueue<Integer> pq = new PriorityQueue<>(); // PriorityQueue is concrete, is a class itself; we’re using it directly as both reference type and implementation
 *
 * ▶ Built-in Type (Array):
 *   - A native language feature, not a class or interface.
 *   - Example:
 *       int[] arr = new int[5]; // Array with fixed size
 *
 * ▶ What We're Doing:
 *   - We'll use Java’s built-in `PriorityQueue` class, which is a concrete class.
 *   - It automatically maintains a **min-heap** structure.
 *   - Elements are returned in priority order (lowest value first by default).
 *   - No need to implement insertion, deletion, or heap logic ourselves.
 */


public class PriorityQueueReview {
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // Instantiate a PriorityQueue of Integers, this is a min heap 
        // PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        pq.add(10);
        pq.add(5);
        pq.add(20);
        pq.add(1);
        // Poll elements in order of priority (min first):
        while (!pq.isEmpty()) {
            System.out.println("Dequeued: " + pq.poll());
        }
    }
}
