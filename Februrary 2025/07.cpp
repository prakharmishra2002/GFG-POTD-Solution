#include <vector>
#include <stack>
using namespace std;

// Tree Node
// class Node {
//   public:
//     int data;
//     Node* left;
//     Node* right;

//     // Constructor to initialize a new node
//     Node(int val) {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> result;
        stack<Node*> stack;
        Node* current = root;

        while (current != NULL || !stack.empty()) {
            // Reach the left most Node of the current Node
            while (current != NULL) {
                stack.push(current);
                current = current->left;
            }
            
            // Current must be NULL at this point
            current = stack.top();
            stack.pop();
            result.push_back(current->data);
            
            // Visit the right subtree
            current = current->right;
        }
        
        return result;
    }
};
