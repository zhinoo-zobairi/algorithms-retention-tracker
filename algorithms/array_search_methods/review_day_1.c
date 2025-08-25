/**
 * Review Day 1 for Array Search Methods
 * Created on 2025-07-20
 *
 * This is your review exercise for Array Search Methods.
 * Complete the implementation below to reinforce your understanding.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Implementation of Array Search Methods
 * TODO: Implement the algorithm from memory to reinforce your learning
 */
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int array_search_methods_linear(int items[], int size, int target) {
    int i = 0;
    while(i < size && items[i] != target){ // If (items[i] != target) is evaluated first and if i == size, that left side already does an out-of-bounds read before the short-circuiting can save you. That’s why you must flip them.
        i++;
    }
    if(i == size){
        return -1;
    }
    if(i > 0){
        swap(&items[i], &items[i-1]);
    }
    return i;
}

int array_search_methods_recursive_binary(const int items[], int lo, int hi, int target){
    if(lo > hi) return -1;
    int mid = lo + (hi - lo) / 2; // must be relative to lo

    if(items[mid] == target) return mid;
    if(target < items[mid]){
        return array_search_methods_recursive_binary(items, lo, mid -1, target);
    } else {
        return array_search_methods_recursive_binary(items, mid + 1, hi, target);
    }
}

int array_search_methods_iterative_binary(const int items[], int lo, int hi, int target){
    while(lo <= hi){
        int mid = lo + (hi-lo) / 2;
        if(items[mid] == target){
            return mid;
        }else if(target > items[mid]){
            lo = mid + 1;
        }else {
            hi = mid - 1;
        }
    }
    return -1;
}
int main() {
    int test_data[] = {2, 5, 6, 7, 9}; // Sorted Input
    int size = sizeof(test_data) / sizeof(test_data[0]);
    
    int result1 = array_search_methods_linear(test_data, size, 10);
    
    printf("%d\n",result1);
    int result2 = array_search_methods_iterative_binary(test_data, 0, 4, 9);
    
    printf("%d\n",result2);

    int result3 = array_search_methods_recursive_binary(test_data, 0, 4, 6);
    
    printf("%d\n",result3);
    return 0;
}
