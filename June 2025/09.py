class Solution:
    def isDeadEnd(self, root):
        def helper(node, min_val, max_val):
            if not node:
                return False
            
            # Dead end condition: min_val == max_val
            if min_val == max_val:
                return True
            
            return (helper(node.left, min_val, node.data - 1) or
                    helper(node.right, node.data + 1, max_val))
        
        return helper(root, 1, float('inf'))
