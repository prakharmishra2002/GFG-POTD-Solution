class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) adj[e[0]].push_back(e[1]);
        vector<int> in(V), res;
        for (auto& e : edges) in[e[1]]++;
        queue<int> q;
        for (int i = 0; i < V; i++) if (!in[i]) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res.push_back(u);
            for (int v : adj[u]) if (--in[v] == 0) q.push(v);
        }
        return res;
    }
};

2)
// ✅ Kahn’s Algorithm (BFS-based Topological Sort)
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> in(V, 0), res;
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (!in[i])
                q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v : adj[u])
                if (--in[v] == 0)
                    q.push(v);
        }
        return res;
    }
};


3)
class Solution {
    void dfs(int u, vector<vector<int>>& g, vector<bool>& vis, stack<int>& st) {
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v]) dfs(v, g, vis, st);
        st.push(u);
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto &e : edges) g[e[0]].push_back(e[1]);
        vector<bool> vis(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
            if (!vis[i]) dfs(i, g, vis, st);
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};


4)
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto &e : edges) g[e[0]].push_back(e[1]);

        vector<bool> vis(V, false), inStack(V, false);
        vector<int> res;
        stack<pair<int, int>> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                st.push({i, 0});
                while (!st.empty()) {
                    int u = st.top().first;
                    int &idx = st.top().second;
                    if (!vis[u]) {
                        vis[u] = true;
                        inStack[u] = true;
                    }
                    bool done = true;
                    while (idx < g[u].size()) {
                        int v = g[u][idx++];
                        if (!vis[v]) {
                            st.push({v, 0});
                            done = false;
                            break;
                        }
                    }
                    if (done) {
                        res.push_back(u);
                        inStack[u] = false;
                        st.pop();
                    }
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
