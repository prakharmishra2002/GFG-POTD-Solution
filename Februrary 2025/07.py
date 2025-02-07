class Solution:
    def inOrder(self, root):
        result = []
        stack = []
        current = root

        while current is not None or stack:
            # Reach the left most Node of the current Node
            while current is not None:
                stack.append(current)
                current = current.left
            
            # Current must be None at this point
            current = stack.pop()
            result.append(current.data)
            
            # Visit the right subtree
            current = current.right
        
        return result
