class Solution {
public:
    void removeLoop(Node* head) {
        Node *slow = head, *fast = head;
        while (fast && fast->next && (slow = slow->next) != (fast = fast->next->next));
        if (!fast || !fast->next) return;
        for (slow = head; slow != fast; slow = slow->next, fast = fast->next);
        while (fast->next != slow) fast = fast->next;
        fast->next = nullptr;
    }
};
