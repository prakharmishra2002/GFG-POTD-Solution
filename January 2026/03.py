class Solution:
    def flatten(self, root):
        if not root:
            return None
        
        # Flatten the remaining list (root.next)
        if root.next:
            root.next = self.flatten(root.next)
        
        # Merge current list with flattened next list
        root = self.merge(root, root.next)
        
        return root
    
    def merge(self, a, b):
        if not a: return b
        if not b: return a
        
        if a.data <= b.data:
            result = a
            result.bottom = self.merge(a.bottom, b)
        else:
            result = b
            result.bottom = self.merge(a, b.bottom)
        
        result.next = None
        return result
