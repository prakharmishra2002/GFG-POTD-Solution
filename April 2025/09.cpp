class Solution {
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Helper function for DFS
        void dfs(int u, int parent, vector<int>& disc, vector<int>& low, 
                 vector<bool>& visited, vector<bool>& ap, vector<int> adj[], int& time) {
            visited[u] = true;
            disc[u] = low[u] = ++time;
            int children = 0;

            for (int v : adj[u]) {
                if (!visited[v]) {
                    children++;
                    dfs(v, u, disc, low, visited, ap, adj, time);
                    low[u] = min(low[u], low[v]);

                    // Check if the node is an articulation point
                    if (parent == -1 && children > 1) ap[u] = true;
                    if (parent != -1 && low[v] >= disc[u]) ap[u] = true;
                } else if (v != parent) {
                    low[u] = min(low[u], disc[v]);
                }
            }
        }

        // Building adjacency list
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false), ap(V, false);
        int time = 0;

        // Run DFS for each unvisited node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, disc, low, visited, ap, adj, time);
            }
        }

        // Collect articulation points
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i]) result.push_back(i);
        }

        return result.empty() ? vector<int>{-1} : result;
    }
};
