class Solution:
    # Function to convert a binary tree into its mirror tree.
    def mirror(self, root):
        if root is None:
            return
        
        # Swap the left and right children
        root.left, root.right = root.right, root.left
        
        # Recursively call mirror on left and right subtrees
        self.mirror(root.left)
        self.mirror(root.right)
