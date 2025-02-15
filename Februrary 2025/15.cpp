class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        while (root && (root->data > max(n1->data, n2->data) || root->data < min(n1->data, n2->data)))
            root = (root->data > n1->data) ? root->left : root->right;
        return root;
    }
};

2)
class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if (!root || root->data == n1->data || root->data == n2->data) return root;
        if (root->data > n1->data && root->data > n2->data) return LCA(root->left, n1, n2);
        if (root->data < n1->data && root->data < n2->data) return LCA(root->right, n1, n2);
        return root;
    }
};

3)
class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        stack<Node*> st;
        while (root) {
            if (root->data > n1->data && root->data > n2->data) root = root->left;
            else if (root->data < n1->data && root->data < n2->data) root = root->right;
            else return root;
        }
        return nullptr;
    }
};
