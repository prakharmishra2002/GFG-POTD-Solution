class Solution {
    int dfs(Node* r, int& res) {
        if (!r) return 0;
        int l = max(0, dfs(r->left, res)), rgt = max(0, dfs(r->right, res));
        res = max(res, l + rgt + r->data);
        return max(l, rgt) + r->data;
    }
public:
    int findMaxSum(Node* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};
