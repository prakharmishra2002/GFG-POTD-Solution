class Solution {
  public:
    bool isBST(Node* root, int min = INT_MIN, int max = INT_MAX) {
        return !root || (root->data > min && root->data < max && isBST(root->left, min, root->data) && isBST(root->right, root->data, max));
    }
};

2)
class Solution {
    void inorder(Node* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->data);
        inorder(root->right, vals);
    }
public:
    bool isBST(Node* root) {
        vector<int> vals;
        inorder(root, vals);
        for (int i = 1; i < vals.size(); i++) {
            if (vals[i] <= vals[i-1]) return false;
        }
        return true;
    }
};

3)
class Solution {
public:
    bool isBST(Node* root) {
        stack<Node*> st;
        Node* prev = nullptr;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (prev && root->data <= prev->data) return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};
