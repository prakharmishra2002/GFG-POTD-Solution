class Solution:
    def isBST(self, root, min_val=float('-inf'), max_val=float('inf')):
        return not root or (min_val < root.data < max_val and
                            self.isBST(root.left, min_val, root.data) and
                            self.isBST(root.right, root.data, max_val))
