#User function Template for python3
from collections import deque

class Solution:
    def bfs(self, adj):
        r, v = [], [False] * len(adj)
        q = deque([0])
        v[0] = True
        while q:
            i = q.popleft()
            r.append(i)
            for j in adj[i]:
                if not v[j]:
                    v[j] = True
                    q.append(j)
        return r
