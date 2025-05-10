# Review Day 14 for Insertion Sort
# Created on 2025-05-10

'''
This is your review exercise for Insertion Sort.
Complete the implementation below to reinforce your understanding.
'''

def insertion_sort(items):
    for i in range(1, len(items)):
        temp = items[i]
        j = i - 1
        while j >= 0 and items[j] > temp:
            items[j+1] = items[j]
            j-=1
        items[j+1] = temp
    return items
if __name__ == "__main__":
    test_data = [5, 2, 9, 1, 5, 6]
    result = insertion_sort(test_data)
    print(f"Result: {result}")
