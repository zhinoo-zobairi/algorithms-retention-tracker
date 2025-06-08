# Counting Sort implementation

def counting_sort(items):
    largest = items[0]
    for i in range(0, len(items)):
        if items[i] > largest:
            largest = items[i]

    aux = [0] * (largest + 1)
    
    for i in range(0, len(items)):
        aux[items[i]] += 1 # for each item in items, in the auxillary array I increment the index, which equals item, by 1
        # then I move to the next item, implicitly i += 1

    # at this point we have a histogram for the values in item and now we have to overwrite the original array:

    j = 0 # pointer to track the indexes in original array, which will be incremented after each round of while
    for i in range(0, len(aux)):
        while aux[i] > 0:
            items[j] = i # we start off by going to the very first index of the original array and write down the exact index of the auxillary array
            aux[i] -= 1 # then we reduce the count of that occurance, if it is not yet zero, we will meet it again in the next round
            j += 1 # we have to of course move to the next index of the items, because this one is filled.


test_array = [3,6,9,1,3,9,11]
counting_sort(test_array)
print(test_array)
