class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        
        // The first element in preorder is the root node
        int rootVal = preorder[0];
        preorder.erase(preorder.begin());
        Node* root = new Node(rootVal);
        
        // Find the index of the root in inorder array
        int inorderIndex = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
        
        // Recursively build the left and right subtree
        vector<int> leftInorder(inorder.begin(), inorder.begin() + inorderIndex);
        vector<int> rightInorder(inorder.begin() + inorderIndex + 1, inorder.end());
        
        root->left = buildTree(leftInorder, preorder);
        root->right = buildTree(rightInorder, preorder);
        
        return root;
    }
};
