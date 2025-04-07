class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Create adjacency list representation of the graph
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Initialize visited and recursion stack
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        // Helper function to perform DFS
        function<bool(int)> dfs = [&](int node) {
            visited[node] = true;
            recStack[node] = true;

            // Traverse neighbors
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    if (dfs(neighbor)) { // Recursive DFS call
                        return true;
                    }
                } else if (recStack[neighbor]) { // Cycle detected
                    return true;
                }
            }

            recStack[node] = false; // Backtrack
            return false;
        };

        // Check for cycles in each component
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i)) {
                    return true;
                }
            }
        }
        return false;
    }
};
