class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for (int i = 0; i < V - 1; ++i)
            for (auto& e : edges)
                if (dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                    dist[e[1]] = dist[e[0]] + e[2];
        for (auto& e : edges)
            if (dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                return {-1};
        return dist;
    }
};

2)
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for (int i = 0; i < V - 1; ++i) {
            bool updated = false;
            for (auto& e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
            if (!updated) break;
        }

        for (auto& e : edges)
            if (dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                return {-1};

        return dist;
    }
};
