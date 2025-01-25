#include <iostream>
using namespace std;
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // Initialize slow and fast pointers
        Node* slow = head;
        Node* fast = head;
        
        // Detect if there is a loop using Floyd's Cycle-Finding Algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        
        // If no loop is found, return NULL
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
        
        // Find the start of the loop
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow; // Return the node itself
    }
};
