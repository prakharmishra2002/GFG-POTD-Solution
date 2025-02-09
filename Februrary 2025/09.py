class Solution:
    def findMaxSum(self, root):
        def dfs(node):
            if not node: return 0
            l = max(0, dfs(node.left))
            r = max(0, dfs(node.right))
            nonlocal res
            res = max(res, l + r + node.data)
            return max(l, r) + node.data
        res = float('-inf')
        dfs(root)
        return res
