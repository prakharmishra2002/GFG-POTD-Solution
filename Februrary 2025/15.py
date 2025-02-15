class Solution:
    def LCA(self, root, n1, n2):
        while root and (root.data - n1.data) * (root.data - n2.data) > 0:
            root = root.left if n1.data < root.data else root.right
        return root
