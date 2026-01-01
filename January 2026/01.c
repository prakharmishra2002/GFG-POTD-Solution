#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to find the intersection point
// Returns the pointer to the intersection node, or NULL if no intersection
struct Node* intersectPoint(struct Node* head1, struct Node* head2) {
    if (head1 == NULL || head2 == NULL) {
        return NULL;
    }
    
    struct Node* a = head1;
    struct Node* b = head2;
    
    // Two pointers traverse the lists
    // When one reaches the end (NULL), it switches to the head of the other list
    while (a != b) {
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }
    
    // Either a and b meet at the intersection node,
    // or both become NULL (no intersection)
    return a;
}
