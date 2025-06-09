#include <bits/stdc++.h>
using namespace std;

/* The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
public:
    bool helper(Node* node, int min_val, int max_val) {
        if (!node)
            return false;

        // Dead end condition: min_val == max_val
        if (min_val == max_val)
            return true;

        return (helper(node->left, min_val, node->data - 1) || 
                helper(node->right, node->data + 1, max_val));
    }

    bool isDeadEnd(Node *root) {
        return helper(root, 1, INT_MAX);
    }
};
