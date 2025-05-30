# Merge implementation

def merge(items_1, items_2):
    i = 0
    j = 0
    new_items = []
    while i<len(items_1) and j<len(items_2):
        if items_1[i] < items_2[j]:
            new_items.append(items_1[i])
            i+=1
        else:
            new_items.append(items_2[j])
            j+=1
    # handling leftovers
    while i < len(items_1):
        new_items.append(items_1[i])
        i += 1
    
    while j < len(items_2):
        new_items.append(items_2[j])
        j+=1

    return new_items