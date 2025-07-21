class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.height = 1
        self.data = data

    def recursive_insert(self, current, new_value):
        if current is None:
            return Node(new_value)
        if new_value < current.data:
            current.left = self.recursive_insert(current.left, new_value)
        else:
            current.right = self.recursive_insert(current.right, new_value)
        
        # Update height: The +1 is because this node adds itself to the height chain.
        current.height = 1 + max(self.height(current.left), self.height(current.right))
        
        # Get balance factor
        balance = self.balance_factor(current)

        # Left Left Case
        if balance > 1 and new_value < current.left.data:
            return self.right_rotate(current)

        # Right Right Case
        if balance < -1 and new_value > current.right.data:
            return self.left_rotate(current)

        # Left Right Case
        if balance > 1 and new_value > current.left.data:
            current.left = self.left_rotate(current.left)
            return self.right_rotate(current)

        # Right Left Case
        if balance < -1 and new_value < current.right.data:
            current.right = self.right_rotate(current.right)
            return self.left_rotate(current)

        return current

# Height = how far down that deepest path goes: Look at how tall the left side is, look at how tall the right side is, and take the bigger one; because height measures the longest path downward.
    
    def height(self, node):
        if node is None:
            return 0  # Changed to 0 to match height stored as 1 in __init__
        return node.height

    def balance_factor(self, node):
        return self.height(node.left) - self.height(node.right)

    def right_rotate(self, z):
        y = z.left
        T3 = y.right

        y.right = z
        z.left = T3

        z.height = 1 + max(self.height(z.left), self.height(z.right))
        y.height = 1 + max(self.height(y.left), self.height(y.right))

        return y

    def left_rotate(self, z):
        y = z.right
        T2 = y.left

        y.left = z
        z.right = T2

        z.height = 1 + max(self.height(z.left), self.height(z.right))
        y.height = 1 + max(self.height(y.left), self.height(y.right))

        return y