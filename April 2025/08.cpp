#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    void dfs(int node, unordered_set<int> &visited, unordered_map<int, vector<int>> &graph) {
        visited.insert(node);
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, visited, graph);
            }
        }
    }

    int countComponents(int V, unordered_map<int, vector<int>> &graph) {
        unordered_set<int> visited;
        int components = 0;
        for (int i = 0; i < V; ++i) {
            if (visited.find(i) == visited.end()) {
                ++components;
                dfs(i, visited, graph);
            }
        }
        return components;
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Build the graph
        unordered_map<int, vector<int>> graph;
        for (const auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Count components in the original graph
        int originalComponents = countComponents(V, graph);

        // Remove the edge (c, d)
        graph[c].erase(remove(graph[c].begin(), graph[c].end(), d), graph[c].end());
        graph[d].erase(remove(graph[d].begin(), graph[d].end(), c), graph[d].end());

        // Count components after removing the edge
        int newComponents = countComponents(V, graph);

        // If the number of components increases, it's a bridge
        return newComponents > originalComponents;
    }
};
