class Solution {
  public:
    string findOrder(vector<string> &w) {
        vector<vector<int>> g(26);
        vector<int> in(26), seen(26);
        for (auto &s : w) for (char c : s) seen[c - 'a'] = 1;
        for (int i = 0; i < w.size() - 1; i++) {
            string &a = w[i], &b = w[i + 1];
            int j = 0, n = min(a.size(), b.size());
            while (j < n && a[j] == b[j]) j++;
            if (j == n && a.size() > b.size()) return "";
            if (j < n) g[a[j] - 'a'].push_back(b[j] - 'a'), in[b[j] - 'a']++;
        }
        queue<int> q;
        for (int i = 0; i < 26; i++) if (seen[i] && !in[i]) q.push(i);
        string res;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res += u + 'a';
            for (int v : g[u]) if (--in[v] == 0) q.push(v);
        }
        for (int i = 0; i < 26; i++) if (seen[i] && in[i]) return "";
        return res;
    }
};

2)
// ✅ C++ Code (Recursive DFS)
class Solution {
    bool dfs(int u, vector<vector<int>> &g, vector<int> &vis, string &res) {
        vis[u] = 1;
        for (int v : g[u]) {
            if (vis[v] == 1) return false;
            if (vis[v] == 0 && !dfs(v, g, vis, res)) return false;
        }
        vis[u] = 2;
        res += (char)(u + 'a');
        return true;
    }
public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> g(26);
        vector<int> seen(26);
        for (auto &w : words)
            for (char c : w) seen[c - 'a'] = 1;
        for (int i = 0; i < words.size() - 1; i++) {
            string &a = words[i], &b = words[i + 1];
            int j = 0, n = min(a.size(), b.size());
            while (j < n && a[j] == b[j]) j++;
            if (j == n && a.size() > b.size()) return "";
            if (j < n) g[a[j] - 'a'].push_back(b[j] - 'a');
        }
        vector<int> vis(26, 0);
        string res;
        for (int i = 0; i < 26; i++)
            if (seen[i] && vis[i] == 0 && !dfs(i, g, vis, res)) return "";
        reverse(res.begin(), res.end());
        return res;
    }
};
