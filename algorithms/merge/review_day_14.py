# Review Day 14 for Merge
# Created on 2025-06-11

'''
This is your review exercise for Merge.
Complete the implementation below to reinforce your understanding.
'''

def merge(items_1, items_2):
    """
    Implementation of Merge
    
    TODO: Implement the algorithm from memory to reinforce your learning
    """
    # Your implementation here
    i = 0
    j = 0
    temp = []
    while i < len(items_1) and j < len(items_2):
        if items_1[i] <= items_2[j]:
            temp.append(items_1[i])
            i += 1
        else:
            temp.append(items_2[j])
            j += 1
    
    while i < len(items_1):
        temp.append(items_1[i])
        i += 1
    while j < len(items_2):
        temp.append(items_2[j])
        j += 1
    
    return temp

# time complexity is O(n + m) => linear in total size

if __name__ == "__main__":
    test_data_1 = [2, 5, 9] # each should be sorted
    test_data_2 = [1, 5, 6]
    result = merge(test_data_1, test_data_2)
    print(f"Result: {result}")
