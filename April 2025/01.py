class Solution:
    def dfs(self, adj):
        r, v = [], [False] * len(adj)
        def go(i):
            v[i] = True
            r.append(i)
            for j in adj[i]:
                if not v[j]:
                    go(j)
        for i in range(len(adj)):
            if not v[i]:
                go(i)
        return r
