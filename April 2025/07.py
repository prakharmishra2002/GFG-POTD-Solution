class Solution:
    def isCycle(self, V, edges):
        # Create adjacency list representation of the graph
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
        
        # Initialize visited and recursion stack
        visited = [False] * V
        recStack = [False] * V
        
        # Helper function to perform DFS
        def dfs(node):
            visited[node] = True
            recStack[node] = True
            
            # Traverse neighbors
            for neighbor in adj[node]:
                if not visited[neighbor]:
                    if dfs(neighbor):  # Recursive DFS call
                        return True
                elif recStack[neighbor]:  # Cycle detected
                    return True
            
            recStack[node] = False  # Backtrack
            return False
        
        # Check for cycles in each component
        for i in range(V):
            if not visited[i]:
                if dfs(i):
                    return True
        
        return False
