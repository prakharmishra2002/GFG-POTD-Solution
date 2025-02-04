class Solution:
    def f(self, r):
        if not r: 
            return (0, 0)
        a, b = self.f(r.left), self.f(r.right)
        h = 1 + max(a[0], b[0])
        d = max(a[1], b[1], a[0] + b[0])
        return (h, d)
    
    def diameter(self, root):
        return self.f(root)[1]
        
