class Solution:
    def sumK(self, r, k):
        self.c = 0
        m = {0: 1}
        def dfs(r, s):
            if not r: return
            s += r.data
            self.c += m.get(s - k, 0)
            m[s] = m.get(s, 0) + 1
            dfs(r.left, s)
            dfs(r.right, s)
            m[s] -= 1
            if m[s] == 0: del m[s]
        dfs(r, 0)
        return self.c
