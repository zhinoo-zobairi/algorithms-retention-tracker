# Review Day 14 for Recursive List Reversal
# Created on 2025-05-11

'''
This is your review exercise for Recursive List Reversal.
Complete the implementation below to reinforce your understanding.
'''

def recursive_list_reversal(items):
    if len(items) <= 1:
        return items
    else:
        return [items[-1]] + recursive_list_reversal(items[:-1]) # int + list → TypeError
                                                                 # list + list → valid

if __name__ == "__main__":
    test_data = [5, 2, 9, 1, 5, 6]
    result = recursive_list_reversal(test_data)
    print(f"Result: {result}")
