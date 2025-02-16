class Solution:
    def serialize(self, root):
        a = []
        def s(r):
            if not r:
                a.append(-1)
                return
            a.append(r.data)
            s(r.left)
            s(r.right)
        s(root)
        return a

    def deSerialize(self, arr):
        self.i = 0
        def d():
            if self.i >= len(arr) or arr[self.i] == -1:
                self.i += 1
                return None
            r = Node(arr[self.i])
            self.i += 1
            r.left = d()
            r.right = d()
            return r
        return d()
