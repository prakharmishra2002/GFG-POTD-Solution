class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == nullptr)
            return;

        // Swap the left and right children
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;

        // Recursively call mirror on left and right subtrees
        mirror(node->left);
        mirror(node->right);
    }
};

// Function to print the inorder traversal of the tree
void inorder(Node *node) {
    if (node == nullptr)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
