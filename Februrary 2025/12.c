int kthSmallest(struct Node* root, int k) {
    while (root) {
        if (!root->left) {
            if (--k == 0) return root->data;
            root = root->right;
        } else {
            struct Node *pre = root->left;
            while (pre->right && pre->right != root) pre = pre->right;
            if (!pre->right) {
                pre->right = root;
                root = root->left;
            } else {
                pre->right = NULL;
                if (--k == 0) return root->data;
                root = root->right;
            }
        }
    }
    return -1;
}
