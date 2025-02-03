class Solution:
    def height(self, root):
        return -1 if not root else 1 + max(self.height(root.left), self.height(root.right))
