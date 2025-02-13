class Solution:
    def findTarget(self, root, target):
        inorder = []
        def inorderTraversal(node):
            if not node:
                return
            inorderTraversal(node.left)
            inorder.append(node.data)
            inorderTraversal(node.right)

        inorderTraversal(root)
        left, right = 0, len(inorder) - 1
        while left < right:
            total = inorder[left] + inorder[right]
            if total == target:
                return True
            if total < target:
                left += 1
            else:
                right -= 1
        return False
