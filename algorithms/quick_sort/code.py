# Quick Sort implementation

def quick_sort(arr, low, high):
    if low < high:
        p = hoare_partition(arr, low, high)
        quick_sort(arr, low, p)
        quick_sort(arr, p + 1, high)


def hoare_partition(arr, low, high):
    pivot = arr[low]
    i = low
    j = high
    while i < j:
        while i <= high and arr[i] <= pivot:
            i += 1
        while j >= low and arr[j] > pivot:
            j -= 1
        if i < j:
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
    arr[low], arr[j] = arr[j], arr[low] # one-liner Pythonic version
    return j

arr = [8, 3, 7, 6, 10, 2, 5]
quick_sort(arr, 0, len(arr) - 1)
print(arr)