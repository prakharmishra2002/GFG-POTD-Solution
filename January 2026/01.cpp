// Definition of the Node structure (usually provided in the problem)
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* intersectPoint(Node* head1, Node* head2) {
        if (head1 == nullptr || head2 == nullptr)
            return nullptr;
        
        Node* a = head1;
        Node* b = head2;
        
        // Traverse both lists
        // When a pointer reaches the end, redirect it to the other head
        while (a != b) {
            a = (a == nullptr) ? head2 : a->next;
            b = (b == nullptr) ? head1 : b->next;
        }
        
        // At this point, either a == b == intersection node
        // or a == b == nullptr (no intersection)
        return a;
    }
};
