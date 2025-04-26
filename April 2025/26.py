class Solution:
    # Your Function Should return True/False
    def isHeap(self, root):
        if not root:
            return True
        
        # Helper function to check completeness
        def isComplete(root):
            queue = [(root, 1)]
            index = 0
            
            while queue:
                node, i = queue.pop(0)
                index += 1
                
                if i != index:
                    return False
                
                if node.left:
                    queue.append((node.left, 2 * i))
                if node.right:
                    queue.append((node.right, 2 * i + 1))
            
            return True
        
        # Helper function to check Max-Heap property
        def isMaxHeap(root):
            if not root:
                return True
            
            if root.left and root.left.data > root.data:
                return False
            if root.right and root.right.data > root.data:
                return False
            
            return isMaxHeap(root.left) and isMaxHeap(root.right)
        
        return isComplete(root) and isMaxHeap(root)
