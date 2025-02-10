class Solution {
public:
    unordered_map<int, int> m;
    int cnt = 0;
    void dfs(Node* node, int k, int currSum) {
        if (!node) return;
        currSum += node->data;
        if (m.count(currSum - k))
            cnt += m[currSum - k];
        m[currSum]++;
        dfs(node->left, k, currSum);
        dfs(node->right, k, currSum);
        m[currSum]--;
    }
    int sumK(Node* root, int k) {
        m[0] = 1;
        dfs(root, k, 0);
        return cnt;
    }
};
