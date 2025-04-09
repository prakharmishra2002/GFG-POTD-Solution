class Solution:
    def articulationPoints(self, V, edges):
        def dfs(u, parent, disc, low, visited, ap, adj, time):
            children = 0
            visited[u] = True
            disc[u] = low[u] = time[0]
            time[0] += 1

            for v in adj[u]:
                if not visited[v]:
                    children += 1
                    dfs(v, u, disc, low, visited, ap, adj, time)
                    low[u] = min(low[u], low[v])

                    # Articulation point conditions
                    if parent is None and children > 1:
                        ap[u] = True
                    if parent is not None and low[v] >= disc[u]:
                        ap[u] = True
                elif v != parent:
                    low[u] = min(low[u], disc[v])

        # Building adjacency list
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        disc = [-1] * V
        low = [-1] * V
        visited = [False] * V
        ap = [False] * V
        time = [0]

        # Run DFS for each unvisited node
        for i in range(V):
            if not visited[i]:
                dfs(i, None, disc, low, visited, ap, adj, time)

        # Collect articulation points
        result = [i for i, is_ap in enumerate(ap) if is_ap]
        return result if result else [-1]
