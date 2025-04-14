// User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
  public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node] = new Node(node->val);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            for (auto nei : cur->neighbors) {
                if (!mp.count(nei)) {
                    mp[nei] = new Node(nei->val);
                    q.push(nei);
                }
                mp[cur]->neighbors.push_back(mp[nei]);
            }
        }
        return mp[node];
    }
};


2)
// ✅ BFS-Based Graph Clone using Queue
class Solution {
  public:
    Node* cloneGraph(Node* node) {
        if (!node) return 0;
        unordered_map<Node*, Node*> m;
        m[node] = new Node(node->val);
        queue<Node*> q{{node}};
        while (!q.empty()) {
            for (auto n : q.front()->neighbors) {
                if (!m[n]) q.push(n), m[n] = new Node(n->val);
                m[q.front()]->neighbors.push_back(m[n]);
            }
            q.pop();
        }
        return m[node];
    }
};



3)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> m;
        return dfs(node, m);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& m) {
        if (m.count(node)) return m[node];
        Node* clone = new Node(node->val);
        m[node] = clone;
        for (Node* neighbor : node->neighbors)
            clone->neighbors.push_back(dfs(neighbor, m));
        return clone;
    }
};


4)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> m;
        stack<Node*> st;
        st.push(node);
        m[node] = new Node(node->val);

        while (!st.empty()) {
            Node* curr = st.top(); st.pop();
            for (auto neighbor : curr->neighbors) {
                if (!m.count(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    st.push(neighbor);
                }
                m[curr]->neighbors.push_back(m[neighbor]);
            }
        }
        return m[node];
    }
};
