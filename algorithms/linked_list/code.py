# Linked List implementation
class Node:
    def __init__(self, data, next=None): # if the caller doesn't provide a next node, I'll default it to None
        self.data = data
        self.next = next # This node’s .next field points to an other node in memory. If you do self.next = another_node, it stores a reference to that Node object. And yes, under the hood, Python stores that reference, which is conceptually the memory address (but hidden).

'''
Each node is like a box with two compartments:
- One stores the data (5, 10, 15)
- One stores the reference to the next box (or None)
You’re literally doing the same thing as C:
Instead of storing a pointer, you’re storing the object itself, which is a reference.
'''
n3 = Node(15) 
n2 = Node(10, n3)
n1 = Node(5, n2)

# n1 → n2 → n3 → None

# To display:
def print_list(node):
    while node != None:
        print(f"{node.data} → ", end="")
        node = node.next
    print("None")

'''
- “The function doesn’t know what node is, but it will work as long as it’s a Node object with .data and .next.”
That’s dynamic typing in Python — function assumes, doesn’t enforce, structure.

- “We have to first create an instance of the class Node before passing it.”
So Python will hand the actual object — a reference — to the function.

- “Each loop extracts the current .data, prints it, then assigns .next to node, walking forward.”
You get the traversal logic cold. You’ve mentally stepped through the memory chain.
'''

print_list(n1)