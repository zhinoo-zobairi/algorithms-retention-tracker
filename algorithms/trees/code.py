# Trees implementation
"""
HOW TO RUN THIS FILE:
Use module execution
From the 'algorithms' directory, run:
    python -m iterative_merge_sort.code
"""
from queue.code import CircularQueue

class Node:
    def __init__(self, value, left= None, right= None): # so we don't have to give None as parameter when creating a node for left and right
        self.value = value
        self.left = left
        self.right = right

def creating_tree():
    root_value = input("Enter root value or None: ")
    if root_value == 'None':
        return None
    root = Node(int(root_value))
    queue = CircularQueue(100) # def __init__(self, size)
    queue.enqueue(root)

    while queue.front != queue.rear:
        current = queue.dequeue()
        left_value = input("Enter left value or None: ")
        if left_value != 'None':
            left_value = int(left_value)
            left_child = Node(left_value)
            current.left = left_child
            queue.enqueue(left_child)
        right_value = input("Enter right value or None: ")
        if right_value != 'None':
            right_value = int(right_value)
            right_child = Node(right_value)
            current.right = right_child
            queue.enqueue(right_child)

# tree traversal      
def display_tree_pre_order(node):
    if node is None:
        return
    print(node.value)
    display_tree_pre_order(node.left)
    display_tree_pre_order(node.right)
    # if there are n nodes, there will be n+1 null pointers, so total number of calls are 2n+1 calls

def display_tree_in_order(node):
    if node is None:
        return
    display_tree_in_order(node.left)
    print(node.value)
    display_tree_in_order(node.right)

def display_tree_post_order(node):
    if node is None:
        return
    display_tree_post_order(node.left)
    display_tree_post_order(node.right)
    print(node.value)

if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2, Node(4))
    root.right = Node(3, Node(5), Node(6))

    print('Preorder:')
    display_tree_pre_order(root)
    print('Inorder:')
    display_tree_in_order(root)
    print('Postorder:')
    display_tree_post_order(root)