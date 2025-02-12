class Solution:
    def kthSmallest(self, root, k):
        while root:
            if not root.left:
                k -= 1
                if k == 0:
                    return root.data
                root = root.right
            else:
                pre = root.left
                while pre.right and pre.right != root:
                    pre = pre.right
                if not pre.right:
                    pre.right = root
                    root = root.left
                else:
                    pre.right = None
                    k -= 1
                    if k == 0:
                        return root.data
                    root = root.right
        return -1
