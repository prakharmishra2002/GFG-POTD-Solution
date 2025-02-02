class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (!root) return {};
        queue<Node *> q({root});
        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back({});
            for (int i = q.size(); i > 0; i--) {
                Node *n = q.front(); q.pop();
                res.back().push_back(n->data);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return res;
    }
};
