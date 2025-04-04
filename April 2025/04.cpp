#include <vector>
using namespace std;

class Solution {
  public:
    // Function to find the root of a node
    int find(vector<int>& parent, int v) {
        if (parent[v] == -1) {
            return v;
        }
        return find(parent, parent[v]);
    }

    // Function to union two nodes and check for cycle
    bool unionSets(vector<int>& parent, int v1, int v2) {
        int root1 = find(parent, v1);
        int root2 = find(parent, v2);
        if (root1 != root2) {
            parent[root1] = root2; // Union the sets
            return false;         // No cycle detected
        }
        return true;              // Cycle detected
    }

    // Function to check if there is a cycle in the graph
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> parent(V, -1); // Initialize parent array with -1

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (unionSets(parent, u, v)) {
                return true; // Cycle found
            }
        }
        return false; // No cycle found
    }
};
