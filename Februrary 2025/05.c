void mirror(Node *node) {
    if (node == NULL)
        return;

    // Swap the left and right children
    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    // Recursively call mirror on left and right subtrees
    mirror(node->left);
    mirror(node->right);
}

// Function to print the inorder traversal of the tree
void inorder(Node *node) {
    if (node == NULL)
        return;

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}
