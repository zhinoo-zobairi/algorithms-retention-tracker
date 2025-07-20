# Binary Search Tree implementation

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None # Starting with an empty tree

# The entire class body is compiled first. All methods become part of the class namespace. When you call self.search(), Python looks up the method on the object, and it doesn’t care where in the file it’s physically written:

    def iterative_insert(self, new):
        # In a BST, the only valid insertion points are at the leaf positions where you fall off (reach None).
        # never need to reshuffle existing nodes.
        if self.root is None:
            self.root = Node(new)
            return True
        prior_temp = self.root
        temp = self.root
        while temp is not None:
            if temp.value == new:
                return False
            elif new > temp.value:
                prior_temp = temp
                temp = temp.right
            else:
                prior_temp = temp
                temp = temp.left
        new_node = Node(new)
        if new > prior_temp.value:
            prior_temp.right = new_node
        else:
            prior_temp.left = new_node
        return True


    def recursive_insert(self, node, new):
        if node is None:
    # Base case: if we've reached a null spot, create and return the new node
    # This return is critical: it should stick to the parent node's .left or .right
            return Node(new)
        if new > node.value:
            node.right = self.recursive_insert(node.right, new)
        else:
            node.left = self.recursive_insert(node.left, new)
        return node # it returns the parent with now an updated left or right field
        

    def iterative_search(self, key):
        current_node = self.root
        while current_node is not None:
            if current_node.value == key:
                return True
            elif key > current_node.value:
                current_node = current_node.right
            else:
                current_node = current_node.left
        return False # maximum comparisons equal to height of the tree
    

    def recursive_search(self, node, key):
        if node is None:
            return False
        elif node.value == key:
            return True
        elif key > node.value:
            return self.recursive_search(node.right, key)
        else:
            return self.recursive_search(node.left, key)


    def build_from_list(self, array):
        for value in array:
            self.insert(value)


    def delete(self, node, key):
        if node is None:
            return node

        if key < node.value:
            node.left = self.delete(node.left, key)
        elif key > node.value:
            node.right = self.delete(node.right, key)
        else:
            # Case 1: No children
            if node.left is None and node.right is None:
                return None

            # Case 2: One child
            if node.left is None:
                return node.right
            if node.right is None:
                return node.left

            # Case 3: Two children
            successor = self.min_value_node(node.right)
            node.value = successor.value
            node.right = self.delete(node.right, successor.value)

        return node


    def min_value_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current
            