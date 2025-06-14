#include <iostream>
using namespace std;

/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    // Helper function to check if two subtrees are mirror images
    bool isMirror(Node* left, Node* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->data == right->data) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    // Main function to check symmetry
    bool isSymmetric(Node* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};
