#include <queue>

class Solution {
  public:
    bool isComplete(Node* root) {
        if (!root) return true;
        
        std::queue<Node*> q;
        q.push(root);
        bool encounteredNull = false;
        
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            if (!node) {
                encounteredNull = true;
            } else {
                if (encounteredNull) return false; // If we encounter a node after null, it's not complete
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }

    bool isMaxHeap(Node* root) {
        if (!root) return true;

        if (root->left && root->left->data > root->data) return false;
        if (root->right && root->right->data > root->data) return false;
        
        return isMaxHeap(root->left) && isMaxHeap(root->right);
    }

    bool isHeap(Node* tree) {
        return isComplete(tree) && isMaxHeap(tree);
    }
};
