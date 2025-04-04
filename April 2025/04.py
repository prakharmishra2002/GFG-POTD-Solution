class Solution:
    def isCycle(self, V, edges):
        parent = [-1] * V

        def find(v):
            if parent[v] == -1:
                return v
            return find(parent[v])

        def union(v1, v2):
            root1 = find(v1)
            root2 = find(v2)
            if root1 != root2:
                parent[root1] = root2
                return False
            return True

        for u, v in edges:
            if union(u, v):  # If union returns True, cycle detected
                return True

        return False
