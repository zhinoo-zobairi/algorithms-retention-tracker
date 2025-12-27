# Review Day 14 for Array Search Methods
# Created on 2025-08-02
<
'''
This is your review exercise for Array Search Methods.
Complete the implementation below to reinforce your understanding.
'''

def array_search_linear(items, target):
    for i, item in enumerate(items):
        if item == target:
            return i
    print("The target item was not found.")
    return -1

#def array_search_binary(items, target):
    