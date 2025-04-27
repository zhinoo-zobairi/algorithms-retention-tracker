# Recursive List Reversal implementation

def recursive_list_reversal(lst):
    if len(lst) <= 1:
        return lst
    else:
        last_element = lst[-1]
        rest_reversed = recursive_list_reversal(lst[:-1])
        return [last_element] + rest_reversed # Recursive Step = Combine small result (one element) + result of recursion on rest.
