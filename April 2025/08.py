class Solution:
    def isBridge(self, V, edges, c, d):
        from collections import defaultdict

        # Function to create the adjacency list
        def create_graph(V, edges):
            graph = defaultdict(list)
            for u, v in edges:
                graph[u].append(v)
                graph[v].append(u)
            return graph

        # DFS to count components
        def dfs(node, visited, graph):
            visited[node] = True
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    dfs(neighbor, visited, graph)

        # Count connected components
        def count_components(graph):
            visited = [False] * V
            components = 0
            for i in range(V):
                if not visited[i]:
                    components += 1
                    dfs(i, visited, graph)
            return components

        # Create the graph
        graph = create_graph(V, edges)

        # Count components in the original graph
        original_components = count_components(graph)

        # Remove the edge (c, d) from the graph
        graph[c].remove(d)
        graph[d].remove(c)

        # Count components after removing the edge
        new_components = count_components(graph)

        # If the number of components increases, it's a bridge
        return new_components > original_components
