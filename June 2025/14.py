class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

class Solution:
    def isSymmetric(self, root):
        # Helper function to check if two subtrees are mirror images
        def isMirror(left, right):
            if not left and not right:
                return True
            if not left or not right:
                return False
            return (left.data == right.data) and isMirror(left.left, right.right) and isMirror(left.right, right.left)
        
        # If root is None, it's symmetric
        if not root:
            return True
        return isMirror(root.left, root.right)
