class Solution:
    def bellmanFord(self, V, edges, src):
        dist = [int(1e8)] * V
        dist[src] = 0
        for _ in range(V - 1):
            for u, v, w in edges:
                if dist[u] < 1e8 and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
        for u, v, w in edges:
            if dist[u] < 1e8 and dist[u] + w < dist[v]:
                return [-1]
        return dist
