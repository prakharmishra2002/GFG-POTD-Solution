class Solution {
public:
    void inorder(Node* root, int& k, int& res) {
        if (!root) return;
        inorder(root->left, k, res);
        if (--k == 0) { res = root->data; return; }
        inorder(root->right, k, res);
    }
    int kthSmallest(Node* root, int k) {
        int res = -1;
        inorder(root, k, res);
        return res;
    }
};

2)
class Solution {
public:
    int kthSmallest(Node* root, int k) {
        if (!root) return -1; 
        stack<Node*> st;
        while (true) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (st.empty()) return -1;
            root = st.top(); st.pop();
            if (--k == 0) return root->data; 
            root = root->right;
        }
    }
};


3)
class Solution {
public:
    int kthSmallest(Node* root, int &k) {
        if (!root) return -1;
        int left = kthSmallest(root->left, k);
        if (k == 0) return left;
        if (--k == 0) return root->data;
        return kthSmallest(root->right, k);
    }
};


4)
class Solution {
  public:
    int kthSmallest(Node* root, int k) {
        while (root) {
            if (!root->left) {
                if (--k == 0) return root->data;
                root = root->right;
            } else {
                Node* pre = root->left;
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
};
