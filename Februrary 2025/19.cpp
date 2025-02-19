#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Linked list Node structure
// struct Node {
//     int data;
//     Node* next;

//     Node(int x) {
//         data = x;
//         next = NULL;
//     }
// };

class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        auto compare = [](Node* a, Node* b) {
            return a->data > b->data;
        };
        priority_queue<Node*, vector<Node*>, decltype(compare)> minHeap(compare);

        // Add the first node of each list to the heap
        for (Node* l : arr) {
            if (l) {
                minHeap.push(l);
            }
        }

        // Create a dummy node to form the merged list
        Node* dummy = new Node(0);
        Node* current = dummy;

        // Extract the smallest element from the heap and add it to the merged list
        while (!minHeap.empty()) {
            Node* node = minHeap.top();
            minHeap.pop();
            current->next = new Node(node->data);
            current = current->next;
            if (node->next) {
                minHeap.push(node->next);
            }
        }

        // Return the head of the merged list
        return dummy->next;
    }
};
