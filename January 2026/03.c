#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;
};

// Helper function to merge two sorted lists (using bottom pointers)
struct Node* merge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;
    
    struct Node* result;
    
    if (a->data <= b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    
    result->next = NULL;  // Important: break horizontal connection
    return result;
}

// Main flatten function
struct Node* flatten(struct Node* root) {
    if (!root) return NULL;
    
    // Recursively flatten the list starting from root->next
    if (root->next) {
        root->next = flatten(root->next);
    }
    
    // Merge current list with the flattened next list
    root = merge(root, root->next);
    
    return root;
}

// Utility function to create new node (optional, for testing)
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->bottom = NULL;
    return node;
}
