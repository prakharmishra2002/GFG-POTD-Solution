class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

class Solution:
    def boundaryTraversal(self, root):
        if not root:
            return []

        def left_boundary(node):
            boundary = []
            while node:
                if node.left or node.right:  # Skip leaf nodes
                    boundary.append(node.data)
                node = node.left if node.left else node.right
            return boundary

        def leaf_nodes(node):
            if not node:
                return []
            if not node.left and not node.right:
                return [node.data]
            return leaf_nodes(node.left) + leaf_nodes(node.right)

        def right_boundary(node):
            boundary = []
            while node:
                if node.left or node.right:  # Skip leaf nodes
                    boundary.append(node.data)
                node = node.right if node.right else node.left
            return boundary[::-1]  # Reverse

        if not root.left and not root.right:
            return [root.data]

        left = left_boundary(root.left)
        leaves = leaf_nodes(root.left) + leaf_nodes(root.right)
        right = right_boundary(root.right)

        return [root.data] + left + leaves + right
