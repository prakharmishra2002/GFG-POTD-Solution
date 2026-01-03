#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
    
    Node(int val) {
        data = val;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution {
public:
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        
        Node* result;
        if (a->data <= b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }
        
        result->next = nullptr;  // Remove horizontal link
        return result;
    }
    
    Node* flatten(Node* root) {
        if (!root) return nullptr;
        
        // Recursively flatten the next list
        if (root->next) {
            root->next = flatten(root->next);
        }
        
        // Merge current vertical list with flattened next list
        root = merge(root, root->next);
        
        return root;
    }
};
