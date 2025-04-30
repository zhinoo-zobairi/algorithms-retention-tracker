/**
 * Review Day 3 for Recursive List Reversal
 * Created on 2025-04-30
 *
 * This is your review exercise for Recursive List Reversal.
 * Complete the implementation below to reinforce your understanding.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class RecursiveListReversal { 
    public static List<Integer> recursive_list_reversal(int[] items, int index, List<Integer> result) { // the method belongs to the class itself (like a universal fact or tool); doesn't depend on object state, method works purely with input parameters. → perfect as static; other than  instance methods when the method works with data inside the object (this.field).
        if (index < 0) {                                                                               
            return result;
        }
        else{
            result.add(items[index]);
            return recursive_list_reversal(items, index-1, result);
        }

    }
    
    public static void main(String[] args) {
        int[] testData = {5, 2, 9, 1, 5, 6};
        List<Integer> reversed = recursive_list_reversal(testData, testData.length - 1, new ArrayList<>()); // We make a new list and determine the index ant the very beginning, so that the functiuon can work with it till the end.
        System.out.println("Result: " + reversed);
    }
}
