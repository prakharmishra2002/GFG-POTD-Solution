class Solution:
    def findDuplicate(self, a):
        s = f = a[0]
        while True:
            s = a[s]
            f = a[a[f]]
            if s == f: break
        f = a[0]
        while s != f:
            s = a[s]
            f = a[f]
        return s
