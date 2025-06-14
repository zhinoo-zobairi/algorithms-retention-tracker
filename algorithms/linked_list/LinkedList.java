/**
 * Review Day 3 for Linked List
 * Created on 2025-06-14
 *
 * This is your review exercise for Linked List.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.Arrays;


public class LinkedList {

    public class Node {
        int value;      // this is the data
        Node next;      // this is the link, each node contains a reference to another of its own kind

        Node(int value){
            this.value = value;
            this.next = null;
    }
};

    public Node linked_list(int[] items) {
        Node head = null; // like in C where we used struct node* head = NULL, this head holds the address/reference to the first node.

        Node prev = null;

        for (int index = 0; index < items.length; index++) {
            if (head == null) {
                head = new Node(items[index]);
                prev = head;
            } else {
                Node node = new Node(items[index]);
                prev.next = node; // Hey previous node, in your next field, store the location of this brand new guy I just made.
                prev = node;      // I save this new guy's address inside 'prev', so I can do the step above again for the next node
            }
        }
       return head; // my only permanent access point to the whole list.
    }

    public void print_linked_list(Node head) {  // Accepts a reference to the head node, Doesn’t return anything, just prints
        
        Node node = head;                       // start walking from the head of the list, Protects the original head from being changed later.                               
                                                
                                                // node.next != null “As long as the next node exists…” last Node won't be printed
        while (node != null){                  // node != null “As long as the current node exists”
            System.out.println(node.value);
            node = node.next;
        }                   
    }
    
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        LinkedList list = new LinkedList();          
        LinkedList.Node head = list.linked_list(testData); //Node is an inner class of LinkedList. So in order to reference it from outside (like from main()), you need to fully qualify it:

        list.print_linked_list(head);              
    }
}
