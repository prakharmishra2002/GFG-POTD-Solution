class Solution {
public:
    bool findTarget(Node* root, int target) {
        vector<int> inorder;
        function<void(Node*)> traverse = [&](Node* node) {
            if (!node) return;
            traverse(node->left);
            inorder.push_back(node->data);
            traverse(node->right);
        };
        traverse(root);
        int left = 0, right = inorder.size() - 1;
        while (left < right) {
            int sum = inorder[left] + inorder[right];
            if (sum == target) return true;
            sum < target ? left++ : right--;
        }
        return false;
    }
};
