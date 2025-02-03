class Solution {
public:
    int height(Node* node) {
        return node ? 1 + max(height(node->left), height(node->right)) : -1;
    }
};
