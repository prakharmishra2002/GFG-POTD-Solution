class Solution:
    def findMinCycle(self, V, edges):
        from heapq import heappush, heappop
        A = [[] for _ in range(V)]
        for u, v, w in edges:
            A[u].append((v, w))
        r = float('inf')
        for i in range(V):
            D = [int(1e9)] * V
            P = [-1] * V
            D[i] = 0
            Q = [(0, i)]
            while Q:
                d, u = heappop(Q)
                for v, w in A[u]:
                    if D[v] > d + w:
                        D[v] = d + w
                        P[v] = u
                        heappush(Q, (D[v], v))
                    elif P[u] != v and P[v] != u:
                        r = min(r, D[u] + D[v] + w)
        return -1 if r == float('inf') else r
