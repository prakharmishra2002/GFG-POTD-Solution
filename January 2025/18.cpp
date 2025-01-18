class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        return prev;
    }
};
