class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None

# Solution class
class Solution:
    def buildTree(self, inorder, preorder):
        if not preorder or not inorder:
            return None
        
        # The first element in preorder is the root node
        root_val = preorder.pop(0)
        root = Node(root_val)
        
        # Find the index of the root in inorder array
        inorder_index = inorder.index(root_val)
        
        # Recursively build the left and right subtree
        root.left = self.buildTree(inorder[:inorder_index], preorder)
        root.right = self.buildTree(inorder[inorder_index+1:], preorder)
        
        return root
