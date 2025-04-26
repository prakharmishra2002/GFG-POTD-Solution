#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to check completeness of binary tree
bool isComplete(struct Node* root) {
    if (!root) return true;
    
    struct Node* queue[1000]; // Simple queue for level-order traversal
    int front = 0, rear = 0;
    queue[rear++] = root;
    bool encounteredNull = false;
    
    while (front < rear) {
        struct Node* node = queue[front++];
        
        if (!node) {
            encounteredNull = true;
        } else {
            if (encounteredNull) return false; // If a null node was encountered earlier, it's not complete
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }
    
    return true;
}

// Function to check Max-Heap property
bool isMaxHeap(struct Node* root) {
    if (!root) return true;

    if (root->left && root->left->data > root->data) return false;
    if (root->right && root->right->data > root->data) return false;

    return isMaxHeap(root->left) && isMaxHeap(root->right);
}

// Main function to check if the binary tree is a heap
bool isHeap(struct Node* root) {
    return isComplete(root) && isMaxHeap(root);
}
