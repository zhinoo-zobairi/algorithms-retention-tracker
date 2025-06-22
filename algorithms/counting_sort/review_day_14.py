# Review Day 14 for Counting Sort
# Created on 2025-06-22

'''
This is your review exercise for Counting Sort.
Complete the implementation below to reinforce your understanding.
'''

def counting_sort(items):
    """
    Implementation of Counting Sort
    
    TODO: Implement the algorithm from memory to reinforce your learning
    """
    frequency = [0] * (max(items) + 1)

    for i in range(0, len(items)):
        frequency[items[i]] += 1
    j = 0
    for i in range(0, len(frequency)):
        while frequency[i] > 0:
            items[j] = i
            frequency[i] -= 1
            j += 1
    return items

if __name__ == "__main__":
    test_data = [5, 2, 9, 1, 5, 6]
    result = counting_sort(test_data)
    print(f"Result: {result}")
