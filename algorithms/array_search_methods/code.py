# Array Search Methods implementation

def array_search_methods_linear(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            if i > 0: # checks that i is not at index 0
                arr[i], arr[i-1] = arr[i-1], arr[i]  # Transposition
                return i-1  # New index after swap
            return i
    return -1

# array should be sorted
def array_search_methods_iterative_binary(arr, target):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def array_search_methods_recursive_binary(array, l, h, target):
    if l <= h:
        mid = (l + h) // 2
        if target == array[mid]:
            return mid
        elif target < array[mid]:
            return array_search_methods_recursive_binary(l,mid-1, target)
        else:
            return array_search_methods_recursive_binary(mid+1, h, target)
    return -1