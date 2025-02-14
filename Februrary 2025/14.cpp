class Solution {
public:
    void correctBST(Node *root) {
        Node *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;
        function<void(Node*)> inorder = [&](Node* node) {
            if (!node) return;
            inorder(node->left);
            if (prev && node->data < prev->data) {
                if (!first) first = prev, middle = node;
                else last = node;
            }
            prev = node;
            inorder(node->right);
        };
        inorder(root);
        swap(first->data, last ? last->data : middle->data);
    }
};

2)
class Solution {
public:
    void correctBST(Node* root) {
        stack<Node*> st;
        Node *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;
        
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if (prev && root->data < prev->data) {
                if (!first) first = prev, middle = root;
                else last = root;
            }
            prev = root;
            root = root->right;
        }
        
        swap(first->data, last ? last->data : middle->data);
    }
};

3)
class Solution {
public:
    void correctBST(Node* root) {
        Node *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;
        
        while (root) {
            if (!root->left) {
                if (prev && root->data < prev->data) {
                    if (!first) first = prev, middle = root;
                    else last = root;
                }
                prev = root;
                root = root->right;
            } else {
                Node* pre = root->left;
                while (pre->right && pre->right != root) pre = pre->right;
                if (!pre->right) {
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = nullptr;
                    if (prev && root->data < prev->data) {
                        if (!first) first = prev, middle = root;
                        else last = root;
                    }
                    prev = root;
                    root = root->right;
                }
            }
        }
        swap(first->data, last ? last->data : middle->data);
    }
};
