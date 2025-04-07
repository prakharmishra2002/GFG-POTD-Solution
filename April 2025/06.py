
from collections import deque

class Solution:
    def topoSort(self, V, edges):
        g = [[] for _ in range(V)]
        in_deg = [0] * V
        res = []
        for u, v in edges:
            g[u].append(v)
            in_deg[v] += 1
        q = deque(i for i in range(V) if in_deg[i] == 0)
        while q:
            u = q.popleft()
            res.append(u)
            for v in g[u]:
                in_deg[v] -= 1
                if in_deg[v] == 0:
                    q.append(v)
        return res
