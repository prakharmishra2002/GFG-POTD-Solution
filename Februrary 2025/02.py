class Solution:
    def levelOrder(self, root):
        if not root: return []
        res, q = [], [root]
        while q:
            res.append([n.data for n in q])
            q = [c for n in q for c in (n.left, n.right) if c]
        return res
