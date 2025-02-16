class Solution {
  public:
    void serializeUtil(Node *root, vector<int> &a) {
        if (!root) { a.push_back(-1); return; }
        a.push_back(root->data);
        serializeUtil(root->left, a);
        serializeUtil(root->right, a);
    }

    vector<int> serialize(Node *root) {
        vector<int> a;
        serializeUtil(root, a);
        return a;
    }

    Node *buildTree(vector<int> &a, int &i) {
        if (i >= a.size() || a[i] == -1) return i++, nullptr;
        Node *root = new Node(a[i++]);
        root->left = buildTree(a, i);
        root->right = buildTree(a, i);
        return root;
    }

    Node *deSerialize(vector<int> &a) {
        int i = 0;
        return buildTree(a, i);
    }
};
