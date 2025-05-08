/**
 * Review Day 3 for Binary Heap Insert Operation
 * Created on 2025-05-08
 *
 * This is your review exercise for Binary Heap Insert Operation.
 * Complete the implementation below to reinforce your understanding.
 */

public class BinaryHeapInsertOperation { // BinaryHeapInsertOperation object has the following fields:
    int[] array; 
    int size;
    int capacity;
    BinaryHeapInsertOperation(int[] array, int capacity, int size){ // A constructor is a method: With the same name as the class, No return type (not even void), And it runs automatically when you create a new object. The user provides the initial heap array, the capacity, and the current number of real heap elements (size).
        this.capacity = capacity;
        this.size = size; // The number of real heap elements provided by the user. Index 0 is reserved as a sentinel and not counted.
        this.array = array;
    }
    public void binary_heap_insert_operation(int element) {  // In instance mode, the methods can always use the object’s fields without passing them explicitly using this.array.
        if (this.size == this.capacity) {
            System.out.println("Memory is full, cannot insert a new element");
        }else{
            this.array[this.size + 1] = element;
            int i = this.size + 1;
            while (i > 1 && element > this.array[i / 2]){
                this.array[i] = this.array[i/2];
                i = i/2;
            }
            this.array[i] = element;
        }
    }
    
    public static void main(String[] args) {
        int[] testData = new int[8];
        testData[0] = -1; // Sentinel
        testData[1] = 9;
        testData[2] = 7;
        testData[3] = 6;
        testData[4] = 5;
        testData[5] = 4;
        testData[6] = 3;
    
        int capacity = 7;
        int size = 6; // We have 6 real heap elements (indices 1 to 6)
    
        BinaryHeapInsertOperation heap = new BinaryHeapInsertOperation(testData, capacity, size);
    
        System.out.print("Initial Heap: ");
        for (int i = 0; i <= heap.size; i++) {
            System.out.print(heap.array[i] + " ");
        }
        System.out.println();
    
        int newElement = 8;
        System.out.println("Inserting element: " + newElement);
        heap.binary_heap_insert_operation(newElement);
    
        System.out.print("Heap after insertion: ");
        for (int i = 0; i <= heap.size; i++) {
            System.out.print(heap.array[i] + " ");
        }
        System.out.println();
    }
}
